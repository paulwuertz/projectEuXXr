//doubly linked list for prim number list
typedef struct Array {
    int used,size;
    int isContinous;
    int* arr;
} Array;

void initArray(Array* arr,int size){
    arr->used=0;
    arr->isContinous=1;
    arr->size=size;
    arr->arr = (int*) malloc (size*sizeof(int));
    if(arr->arr==NULL) assert("Init of Array failed...");
}

void freeArray(Array* arr){
    free(arr->arr);
}

void addArray(Array* arr,int ele){
    arr->used++;
    if(arr->used>arr->size){ 
        arr->size*=2;
        arr->arr = (int*) realloc (arr->arr, arr->size * sizeof(int));
    }
    if(arr->arr==NULL) assert("Resize during add of Array failed...");
    *(arr->arr+arr->used-1)=ele;
}

void setArray(Array* arr, int pos, int ele){
    arr->used++;
    if(pos>arr->size){ 
        arr->size*=pos*2;
        arr->isContinous=0;
        arr->arr = (int*) realloc (arr->arr, 2 * pos * sizeof(int));
    }
    if(arr->arr==NULL) assert("Resize during set of Array failed...");
    *(arr->arr+pos)=ele;
}

int getArray(Array* arr,int ind){
    if(ind>arr->used) assert("Indexing of Array failed...");
    return *(arr->arr+ind);
}