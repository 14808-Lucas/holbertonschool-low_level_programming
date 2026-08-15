#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * dup_string - duplicate a NUL-terminated string onto the heap
 * @s: string to duplicate
 *
 * Return: pointer to the newly allocated copy, or NULL on failure
 * or if s is NULL
 */
static char *dup_string(const char *s)
{
	size_t len;
	char *copy;

	if (!s)
		return (NULL);

	len = strlen(s);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);

	memcpy(copy, s, len + 1);
	return (copy);
}

/**
 * init_data - allocate and populate a session's data buffer
 * @s: session whose data/data_len fields will be set
 * @data: source data to copy in (may be NULL if data_len is 0)
 * @data_len: length of data in bytes
 *
 * Return: 1 on success, 0 on allocation failure
 */
static int init_data(session_t *s, const unsigned char *data,
	size_t data_len)
{
	if (data_len == 0)
	{
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	s->data = malloc(data_len);
	if (!s->data)
		return (0);

	memcpy(s->data, data, data_len);
	s->data_len = data_len;
	return (1);
}

/**
 * session_create - allocate and initialize a new session
 * @id: session identifier string (deep-copied, caller retains ownership
 * of the original)
 * @uid: user id to store in the session
 * @data: initial data buffer to copy into the session (may be NULL
 * if data_len is 0)
 * @data_len: length of data in bytes
 *
 * Return: pointer to the newly allocated session, or NULL on failure
 */
session_t *session_create(const char *id, unsigned int uid,
	const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (!id)
		return (NULL);

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);

	/*
	 * The caller's id buffer may have a lifetime shorter than the
	 * session (e.g. a stack line buffer reused each loop iteration),
	 * so the session must own its own copy.
	 */
	s->id = dup_string(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	s->uid = uid;
	if (!init_data(s, data, data_len))
	{
		free(s->id);
		free(s);
		return (NULL);
	}

	return (s);
}

/**
 * session_set_data - replace a session's data buffer
 * @s: session to update
 * @data: new data to copy in (may be NULL if data_len is 0)
 * @data_len: length of the new data in bytes; 0 clears the buffer
 *
 * Return: 1 on success, 0 on failure (session is left unchanged
 * on failure)
 */
int session_set_data(session_t *s, const unsigned char *data,
	size_t data_len)
{
	unsigned char *tmp;

	if (!s)
		return (0);

	if (data_len == 0)
	{
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	/*
	 * Allocate into a temporary first so a failed allocation never
	 * clobbers the still-valid existing buffer (avoids a lost pointer
	 * on allocation failure).
	 */
	tmp = malloc(data_len);
	if (!tmp)
		return (0);

	memcpy(tmp, data, data_len);
	free(s->data);
	s->data = tmp;
	s->data_len = data_len;

	return (1);
}

/**
 * session_destroy - free a session and all memory it owns
 * @s: session to destroy (safe to call with NULL)
 */
void session_destroy(session_t *s)
{
	if (!s)
		return;
	free(s->id);
	free(s->data);
	free(s);
}
