/*
** == Map ==
**
**  Collection that maps keys to values
**
**  + keys require "Eq" and "Ord"
**  + Just holds references
**  + Not responsible for object deallocation
*/

#ifndef MapPlus_h
#define MapPlus_h

#include "Prelude+.h"
#include "Type+.h"

module Map;

struct MapNode {
  var leaf_key;
  var leaf_val;
  struct MapNode* left;
  struct MapNode* right;
};

data {
  var type;
  var keys;
  struct MapNode* root;
} MapData;

/** Map_New(var self); */
var Map_New(var self, va_list* args);
var Map_Delete(var self);

void Map_Assign(var self, var obj);
var Map_Copy(var self);

int Map_Len(var self);
void Map_Clear(var self);
var Map_Contains(var self, var key);
void Map_Discard(var self, var key);

var Map_Get(var self, var key);
void Map_Put(var self, var key, var val);

var Map_Iter_Start(var self);
var Map_Iter_End(var self);
var Map_Iter_Next(var self, var curr);

instance(Map, New) = { sizeof(MapData), Map_New, Map_Delete };
instance(Map, Assign) = { Map_Assign };
instance(Map, Copy) = { Map_Copy };
instance(Map, Collection) = { Map_Len, Map_Clear, Map_Contains, Map_Discard };
instance(Map, Dict) = { Map_Get, Map_Put };
instance(Map, Iter) = { Map_Iter_Start, Map_Iter_End, Map_Iter_Next };


#endif
