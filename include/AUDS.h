#include <stdlib.h>
#include <iostream>
template <typename T>

/**
 * The Almost Useless Data Structure is a generic data structure that
 * can store an arbitrary number of elements and can only access them
 * at random.
 *
 * @author Ryan Jones
 */
class AUDS {

public:
    AUDS(){
        currentSize = 0;
        currentMax = INITIAL_SIZE;
        nextIndex = 0;
        data = new T[INITIAL_SIZE];
                
    }

    /**
     * Copy constructor to make this object a deep copy of another AUDS
     * @param other Reference to the AUDS to deep copy
     */
    AUDS(const AUDS& other){
        currentSize = other.currentSize;
        currentMax = other.currentMax;
        nextIndex = other.nextIndex;
        
        data = new T[other.currentMax];
        for (int i=0; i < other.nextIndex; i++){
            data[i] = other.data[i];
        }
    }

    /**
     * Copy operator=, assigns to a deep copy
     * @param other The AUDS to  copy
     * @return deep copy of AUDS
     */
    AUDS& operator=(AUDS other) {
        std::swap(currentSize, other.currentSize);
        std::swap(currentMax, other.currentMax);
        std::swap(nextIndex, other.nextIndex);
        std::swap(data, other.data);
    
        return *this;
    }

    ~AUDS(){
        delete[] data;
    }

    /**
     * Adds an element to the end of the AUDS
     * @param e Element to add
     */
    void push(T e){

        // First, expand the array if full
        if (currentSize == currentMax){
            increaseSize();
        }

        data[nextIndex++] = e;
        currentSize++;
    }

    /**
     * Picks random element from AUDS to remove
     * @return Removed element 
     */
    T pop(){
        if (currentSize == 0){
            throw std::runtime_error("Cannot pop empty AUDS");
        }
        int i = rand() % currentSize; //pick random index
        T temp = data[i];

        // fill in hole with last element to save space
        data[i] = data[--nextIndex];
        currentSize--;

        return temp;
    }

    /**
     * @return Number of elements in AUDS
     */
    int size(){
        return currentSize;
    }

private:
    /* Starting size holds 100 elements */
    const int INITIAL_SIZE = 100;
    /* Number of elements in the AUDS */
    int currentSize;
    /* The actual size of the data[] array */
    int currentMax;
    /* Placeholder for the index after the last element in the array */
    int nextIndex;

    /* Stores the elements */
    T* data;

    /**
     * Increases the size of the data[] array by 50%
     */
    void increaseSize(){

        // Create new array with increased size
        currentMax *= 1.5;
        T* newData = new T[currentMax];
       
        // copy old small array into new expanded array
        for (int i = 0; i < nextIndex; i++){
            newData[i] = data[i];
        }

        delete[] data; //free memory of old array
        data = newData;
    }

    
};
