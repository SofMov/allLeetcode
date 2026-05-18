#define debug

typedef struct {
    int* arr;
    int len;
} Fancy;


Fancy* fancyCreate() {
    Fancy* new = malloc(sizeof(Fancy));
    new->len = 0;
    new->arr = (int*)malloc(0);
    return new;
}

void fancyAppend(Fancy* obj, int val) {
    #ifdef debug
    printf("changing length from %d to %d\n",sizeof(Fancy) + sizeof(int)*(obj->len), sizeof(Fancy) + sizeof(int)*(obj->len+1));
    #endif /*debug*/
    obj = realloc(obj, sizeof(Fancy) + sizeof(int)*(obj->len+1)); //add another number
    #ifdef debug
    printf("len:%d, val:%d\n", obj->len, val);
    printf("arr[%d] = %d\n", obj->len, val);
    printf("obj is %s", obj == NULL? "null":"not null");
    #endif
    //obj->arr[obj->len] = val;
    obj->len++;
}

void fancyAddAll(Fancy* obj, int inc) {
    for(int i = 0; i < obj->len; i++){
        obj->arr[i] += inc;
    }
}

void fancyMultAll(Fancy* obj, int m) {
    for(int i = 0; i < obj->len; i++){
        obj->arr[i] *= m;
    }
}

int fancyGetIndex(Fancy* obj, int idx) {
    return obj->arr[idx];
}

void fancyFree(Fancy* obj) {
    free(obj);
}

/**
 * Your Fancy struct will be instantiated and called as such:
 * Fancy* obj = fancyCreate();
 * fancyAppend(obj, val);
 
 * fancyAddAll(obj, inc);
 
 * fancyMultAll(obj, m);
 
 * int param_4 = fancyGetIndex(obj, idx);
 
 * fancyFree(obj);
*/
