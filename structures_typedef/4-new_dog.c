#include <stdlib.h>
#include "dog.h"

/**
 * my_strlen - counts the length of a string
 * @str: the string to measure
 *
 * Return: the length of the string
 */
int my_strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * my_strcpy - copies the string pointed to by src into dest
 * @dest: destination buffer
 * @src: source string
 *
 * Return: a pointer to dest
 */
char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog_t, allocating copies of name and owner
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the owner of the dog
 *
 * Return: a pointer to the new dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *name_copy;
	char *owner_copy;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	name_copy = malloc(sizeof(char) * (my_strlen(name) + 1));
	if (name_copy == NULL)
	{
		free(d);
		return (NULL);
	}
	my_strcpy(name_copy, name);

	owner_copy = malloc(sizeof(char) * (my_strlen(owner) + 1));
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(d);
		return (NULL);
	}
	my_strcpy(owner_copy, owner);

	d->name = name_copy;
	d->age = age;
	d->owner = owner_copy;

	return (d);
}
