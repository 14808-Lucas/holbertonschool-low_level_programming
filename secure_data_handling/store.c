#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_init - initialize an empty store
 * @st: store to initialize
 */
void store_init(store_t *st)
{
	if (st)
		st->head = NULL;
}

/**
 * store_add - insert a session into the store
 * @st: store to insert into
 * @s: session to insert
 *
 * store_add takes ownership of s unconditionally: on success the store
 * owns it, and on any failure path the store destroys it here so the
 * caller never has to (and never could) free it itself.
 *
 * Return: 1 on success, 0 on failure (invalid input, duplicate id,
 * or allocation failure)
 */
int store_add(store_t *st, session_t *s)
{
	node_t *n, *cur;

	if (!st || !s || !s->id)
	{
		session_destroy(s);
		return (0);
	}

	cur = st->head;
	while (cur)
	{
		if (cur->sess && cur->sess->id &&
			strcmp(cur->sess->id, s->id) == 0)
		{
			session_destroy(s);
			return (0);
		}
		cur = cur->next;
	}

	n = malloc(sizeof(*n));
	if (!n)
	{
		session_destroy(s);
		return (0);
	}
	n->sess = s;

	n->next = st->head;
	st->head = n;
	return (1);
}

/**
 * store_get - look up a session by id
 * @st: store to search
 * @id: id to search for
 *
 * Return: pointer to the matching session (still owned by the store),
 * or NULL if not found
 */
session_t *store_get(store_t *st, const char *id)
{
	node_t *cur;

	if (!st || !id)
		return (NULL);

	cur = st->head;
	while (cur)
	{
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, id) == 0)
			return (cur->sess);
		cur = cur->next;
	}
	return (NULL);
}

/**
 * store_delete - remove a session from the store by id
 * @st: store to remove from
 * @id: id to remove
 * @out: if non-NULL, ownership of the removed session transfers here
 * and it is NOT destroyed by the store; if NULL, the store destroys
 * the session itself (delete-and-destroy semantics)
 *
 * Return: 1 if a session was deleted, 0 if not found
 */
int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *cur, *prev;

	if (!st || !id)
		return (0);

	prev = NULL;
	cur = st->head;
	while (cur)
	{
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, id) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				st->head = cur->next;

			if (out)
				*out = cur->sess;
			else
				session_destroy(cur->sess);

			free(cur);
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}

/**
 * store_destroy - free every session and node in the store
 * @st: store to destroy (safe to call with NULL, or repeatedly, or
 * on an already-empty store)
 *
 * Leaves the store in the same empty state as store_init, so it
 * remains safely reusable after this call.
 */
void store_destroy(store_t *st)
{
	node_t *cur, *next;

	if (!st)
		return;

	cur = st->head;
	while (cur)
	{
		next = cur->next;
		session_destroy(cur->sess);
		free(cur);
		cur = next;
	}
	st->head = NULL;
}
