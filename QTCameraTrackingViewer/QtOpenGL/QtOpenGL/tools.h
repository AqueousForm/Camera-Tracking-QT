#pragma once

#define  SAFEDELETE(p) if(p){delete (p); (p) = NULL;}

#define  SAFEDELETES(p) if(p){delete [](p); (p) = NULL;}