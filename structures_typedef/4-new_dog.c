#include "dog.h"
#include <stdlib.h>

/**
 * copy_dog_string - creates a copy of a string
 * @src: string to copy
 *
 * Return: pointer to the copy, or NULL
 */
static char *copy_dog_string(char *src)
{
	size_t len, i;
	char *copy;

	if (src == NULL)
		return (NULL);

	len = 0;
	while (src[len] != '\0')
		len++;

	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = src[i];

	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(*dog));
	if (dog == NULL)
		return (NULL);

	dog->name = NULL;
	dog->owner = NULL;
	dog->age = age;

	if (name != NULL)
	{
		dog->name = copy_dog_string(name);
		if (dog->name == NULL)
		{
			free(dog);
			return (NULL);
		}
	}

	if (owner != NULL)
	{
		dog->owner = copy_dog_string(owner);
		if (dog->owner == NULL)
		{
			free(dog->name);
			free(dog);
			return (NULL);
		}
	}

	return (dog);
}
