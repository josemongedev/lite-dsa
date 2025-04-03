#include <hash_map.h>
#include <stdlib.h>

static lite_hash_map_t *__lite_hash_map_create();
static void __lite_hash_map_put(char *key, char *value);
static char *__lite_hash_map_get(char *key);
static void __lite_hash_map_remove(char *key);

thread_local lite_hash_map_handle_t hash_map_handle = (lite_hash_map_handle_t){
    .map = NULL,
    .create = __lite_hash_map_create,
    .put = __lite_hash_map_put,
    .get = __lite_hash_map_get,
    .remove = __lite_hash_map_remove,
};

lite_hash_map_handle_t *
lite_use_hash_map(lite_hash_map_t *map)
{
    hash_map_handle.map = map;
    return &hash_map_handle;
}

lite_hash_map_t *lite_hash_map_create()
{
}

void lite_hash_map_put(lite_hash_map_t *map, char *key, char *value)
{
}

char *lite_hash_map_get(lite_hash_map_t *map, char *key)
{
}

void lite_hash_map_remove(lite_hash_map_t *map, char *key)
{
}

/* Static functions meant for the Hash Map interface */
static lite_hash_map_t *__lite_hash_map_create()
{
    return lite_hash_map_create();
}

static void __lite_hash_map_put(char *key, char *value)
{
    if (hash_map_handle.map == NULL)
    {
        return;
    }
    lite_hash_map_put(hash_map_handle.map, key, value);
}

static char *__lite_hash_map_get(char *key)
{
    if (hash_map_handle.map == NULL)
    {
        return NULL;
    }
    lite_hash_map_get(hash_map_handle.map, key);
}

static void __lite_hash_map_remove(char *key)
{
    if (hash_map_handle.map == NULL)
    {
        return;
    }
    lite_hash_map_remove(hash_map_handle.map, key);
}