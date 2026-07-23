#include "dog.h"

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to the struct dog to initialize
 * @name: the name to assign to the dog
 * @age: the age to assign to the dog
 * @owner: the owner to assign to the dog
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
