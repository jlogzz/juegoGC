//
//  clases.h
//  juegoGC
//
//  baumann jlo 10/28/15.
//

#include "vars.h"

class Gota {
    
private:
    int x,y,z,v;
    
public:
    Gota(double vel){
        x = (rand() % (2*MAX_X))-MAX_X;
        y = (rand() % (2*MAX_Y))-MAX_Y;
        z = MAX_Z;
        
        //velocidad aleatoria entre min y max multiplicada por vel que va a cambiar con cambio de dificultad
        v = (int)(vel*(VEL_G_MIN + (rand() % (int)(VEL_G_MAX - VEL_G_MIN + 1))));
    }
    
    bool caer(){
        
        //si puede seguir cayendo regresa true, si toca el piso regresa false
        z-=v;
        return (z > 0);
        
        
    }
    
    int getX(){
        return x;
    }
    
    int getY(){
        return y;
    }
    
    int getZ(){
        return z;
    }
    
    
};


class Cubeta {
    
    
private:
    int x, y, v;
    
public:
    Cubeta(int vel){
        x = 0;
        y = 0;
        v = vel;
        
    }
    
    bool mover(char dir){
        switch (dir) {
            case 'l':
                //mover a la izquierda
                if(x > v-1*(MAX_X-v)){
                    x-=v;
                    return true;
                } else {
                    x = v-1*(MAX_X-v);
                    return false;
                }
                break;
            case 'r':
                //mover a la derecha
                if(x < MAX_X-v){
                    x+=v;
                    return true;
                } else {
                    x = MAX_X-v;
                    return false;
                }
                break;
            case 'u':
                //mover hacia 'arriba'
                if(y > -1*(MAX_Y-v)){
                    y-=v;
                    return true;
                } else {
                    y = -1*(MAX_Y-v);
                    return false;
                }
                break;
            case 'd':
                //mover hacia 'abajo'
                if(y < MAX_Y-v){
                    y+=v;
                    return true;
                } else {
                    y = MAX_Y-v;
                    return false;
                }
                break;
                
            default:
                return false;
                break;
        }
    }
    
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    
    
    
};