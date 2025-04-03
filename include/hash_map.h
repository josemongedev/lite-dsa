#ifndef HASH_MAP_H
#define HASH_MAP_H

typedef enum hash_map_type_e
{
    HASH_MAP_TYPE_INT,
    HASH_MAP_TYPE_STRING
} hash_map_type_t;
typedef struct
{
    char *key;
    char *value;
} lite_hash_map_entry_t;

typedef struct
{
    lite_hash_map_entry_t *entries;
    int size;
    int capacity;

} lite_hash_map_t;

typedef lite_hash_map_t *(*lite_fn_create_t)(void);
typedef void (*lite_fn_put_t)(char *key, char *value);
typedef char *(*lite_fn_get_t)(char *key);
typedef void (*lite_fn_remove_t)(char *key);

typedef struct
{
    lite_hash_map_t *map;
    lite_fn_create_t create;
    lite_fn_put_t put;
    lite_fn_get_t get;
    lite_fn_remove_t remove;
} lite_hash_map_handle_t;

lite_hash_map_handle_t *
lite_use_hash_map(lite_hash_map_t *map);
lite_hash_map_t *lite_hash_map_create();
void lite_hash_map_put(lite_hash_map_t *map, char *key, char *value);
char *lite_hash_map_get(lite_hash_map_t *map, char *key);
void lite_hash_map_remove(lite_hash_map_t *map, char *key);

#endif // HASH_MAP_H