#ifndef DOG_H
#define DOG_H

/**
 * struct dog - new type to define a dog
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the name of the dog's owner
 *
 * Description: struct to hold basic info about a dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
#endif /* DOG_H */
