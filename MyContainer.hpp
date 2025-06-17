#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace ContainerNs
{

template<typename T = int>
class MyContainer;

template<typename T> std::ostream &operator<< (std::ostream& os, const MyContainer<T>& container);

template<typename T>

class MyContainer
{
private:
    std::vector<T> elements;

public:
        MyContainer(){} 

/**
 * @brief Adds element to container.
 *
 * 
 *
 * @param item The first item of type T to be added to the container.
 */
        

        void addElement(const T& item){
            elements.push_back(item);
        }

/**
 * @brief removes an item of type T from the container even if it appears multiple times.
 *
 *
 * @param item The first item of type T to be removed from the containe.
 */

        void remove(const T& item) {
            int count = 0;
            for (size_t i = 0; i < elements.size(); ) {
                if (elements[i] == item) {
                    elements.erase(elements.begin() + i);
                    ++count;
                }
                else {
                    ++i;
                }
            }

            if (count == 0) {
                throw std::invalid_argument("Item doesn't exist, try another item!");
            }
        }

/**
 * @brief finds and returns the size of the container.
 * @return The size of the container.
 */



        int size() const{
            return elements.size();
        }

        const std:: vector<T>& getElements() const{
            return elements;
        }

        /**
         * @brief friend function for operator <<.
         *
         * 
         *
         * @param os os stream .
         * @param container a container of type T.
         * 
         */
       

        friend std::ostream &operator<< <T>(std::ostream& os, const MyContainer<T>& container);



        class AscendingOrder
        {

        private:
                std::vector<T> sortedElements;
                size_t indexOfElements;
                        
        public:
            AscendingOrder(const MyContainer& container,size_t intialize_Index): 
                        sortedElements(container.elements), indexOfElements(intialize_Index){
                std::sort(sortedElements.begin(), sortedElements.end());
            }

            /**
             * @brief operator* , for dereferencing and accssing elements in the container.
             *
             * 
             *
             * 
             * 
             * @return the element in the sortedelement container.
             */

            const T& operator*() const{
                return sortedElements[indexOfElements];
            }

            /**
             * @brief operator for pre increment of the container.
             *
             * 
             *
             * 
             * @return increments and returns the value of this.
             */

            AscendingOrder& operator++(){
                ++indexOfElements;
                return (*this);
            }
            /**
             * @brief operator[] for accessing an element in the container through an index.
             *
             * 
             *
             * @param index index of users choice , as long as it exists.
             * 
             * @return The element in the container corresponding to the index if it exists.
             */

            const T& operator[](size_t index){
                if (index<0 || index>this->sortedElements.size())
                {
                    throw std::out_of_range("Index is invalid, try again!");
                }
                else{
                    return (this->sortedElements[index]);
                }
                
            }

            /**
             * @brief operator == , to check if to containers are equal.
             *
             * 
             *
             * @param other another container of the same type.
             * 
             * @return return if they are equal or not
             */


            bool operator==(const AscendingOrder& other) const{

                return indexOfElements == other.indexOfElements;


            }

            /**
             * @brief operator != , to check if to containers are not equal.
             *
             * 
             *
             * @param other another container of the same type.
             * 
             * @return return if they are equal or not
             */

             bool operator!=(const AscendingOrder& other) const{

                return !(*this==other);


            }

         
        };
        AscendingOrder begin_ascending_order() const { return AscendingOrder(*this,0); }
        AscendingOrder end_ascending_order() const { return AscendingOrder(*this,this->elements.size()); }


        class DescendingOrder{
            private:
                    std::vector<T> sortedElements;
                    size_t indexOfElements;
            public:
                    DescendingOrder(const MyContainer& container, size_t initialize_Index): sortedElements(container.elements),indexOfElements(initialize_Index){
                        std::sort(sortedElements.begin(), sortedElements.end(), std::greater<T>());
                    }

                    /**
                     * @brief operator* , for dereferencing and accssing elements in the container.
                     *
                     * 
                     *
                     * 
                     * 
                     * @return the element in the sortedelement container.
                     */

                    const T& operator*() const{
                        return sortedElements[indexOfElements];
                    }

                    /**
                     * @brief operator for pre increment of the container.
                     *
                     * 
                     *
                     * 
                     * @return increments and returns the value of this.
                     */

                    DescendingOrder& operator++( ){
                         ++indexOfElements;
                        return (*this);
                    }


                    /**
                     * @brief operator == , to check if to containers are equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */



                    bool operator==( const DescendingOrder& other) const{
                        return (this->indexOfElements == other.indexOfElements);

                    }

                    /**
                     * @brief operator != , to check if to containers are not equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */

                    bool operator !=(const DescendingOrder& other) const{
                        return !(*this == other);
                    }

                    /**
                     * @brief operator[] for accessing an element in the container through an index.
                     *
                     * 
                     *
                     * @param index index of users choice , as long as it exists.
                     * 
                     * @return The element in the container corresponding to the index if it exists.
                     */



                    const T& operator[](size_t index){
                    if (index<0 || index>this->sortedElements.size())
                    {
                        throw std::out_of_range("Index is invalid, try again!");
                    }
                    else{
                        return (this->sortedElements[index]);
                    }
                
            }
        };

        DescendingOrder begin_descending_order() const { return DescendingOrder(*this,0); }
        DescendingOrder end_descending_order() const { return DescendingOrder(*this,this->elements.size()); }

        class SideCrossOrder{
            private:
                    std::vector<T> sortedElements;
                    size_t indexOfElements;

            public:
                    SideCrossOrder(const MyContainer& container,size_t initialize_Index): indexOfElements(initialize_Index){
                        std::vector<T> sorted = container.getElements();
                        std::sort(sorted.begin(),sorted.end());

                        size_t left = 0;
                        size_t right = sorted.size()-1;

                        while (left<=right)
                        {
                            if (left==right)
                            {
                                sortedElements.push_back(sorted[left]);
                            }

                            else{
                                sortedElements.push_back(sorted[left]);
                                sortedElements.push_back(sorted[right]);
                            }
                            ++left;
                            --right;

                        }
                    }
                    /**
                     * @brief operator* , for dereferencing and accssing elements in the container.
                     *
                     * 
                     *
                     * 
                     * 
                     * @return the element in the sortedelement container.
                     */



                    const T& operator*(){
                        return sortedElements[indexOfElements];
                    }
                   
                    /**
                     * @brief operator for pre increment of the container.
                     *
                     * 
                     *
                     * 
                     * @return increments and returns the value of this.
                     */




                    SideCrossOrder& operator++(){
                        ++indexOfElements;
                        return (*this);
                    }

                    /**
                     * @brief operator == , to check if to containers are equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */



                     bool operator==( const SideCrossOrder& other) const{
                        return(this->indexOfElements==other.indexOfElements);
                    }

                    /**
                     * @brief operator != , to check if to containers are not equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */

                    bool operator!=(const SideCrossOrder& other) const{
                        return!(this->indexOfElements==other.indexOfElements);
                    }

                    /**
                     * @brief operator[] for accessing an element in the container through an index.
                     *
                     * 
                     *
                     * @param index index of users choice , as long as it exists.
                     * 
                     * @return The element in the container corresponding to the index if it exists.
                     */



                    const T& operator[](size_t index){
                    if (index<0 || index>this->sortedElements.size())
                    {
                        throw std::out_of_range("Index is invalid, try again!");
                    }
                    else{
                        return (this->sortedElements[index]);
                    }

                    }

        };

         SideCrossOrder begin_side_cross_order() const { return SideCrossOrder(*this,0); }
         SideCrossOrder end_side_cross_order() const { return SideCrossOrder(*this,this->elements.size()); }

        class ReverseOrder{

            private:
                    std::vector<T> sortedElements;
                    size_t indexOfElements;

            public:
                    ReverseOrder(const MyContainer& container, size_t initialize_Index):sortedElements(container.elements), indexOfElements(initialize_Index){
                        std::reverse(sortedElements.begin(), sortedElements.end());
                        
                    }

                     
                    /**
                     * @brief operator* , for dereferencing and accssing elements in the container.
                     *
                     * 
                     *
                     * 
                     * 
                     * @return the element in the sortedelement container.
                     */
                    const T& operator*(){
                        return (sortedElements[indexOfElements]);
                    }


                     


                    /**
                     * @brief operator for pre increment of the container.
                     *
                     * 
                     *
                     * 
                     * @return increments and returns the value of this.
                     */
                    ReverseOrder& operator++(){
                        ++ indexOfElements;
                        return (*this);

                    }


                     


                    /**
                     * @brief operator == , to check if to containers are equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */
                    bool operator==(const ReverseOrder& other) const{
                        return(this->indexOfElements==other.indexOfElements);
                    }

                     
                    /**
                     * @brief operator != , to check if to containers are not equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */
                    bool operator!=(const ReverseOrder& other) const{
                        return!(this->indexOfElements==other.indexOfElements);
                    }

                   
                   
                   
                   
                   
                   
                    



                     /**
                     * @brief operator[] for accessing an element in the container through an index.
                     *
                     * 
                     *
                     * @param index index of users choice , as long as it exists.
                     * 
                     * @return The element in the container corresponding to the index if it exists.
                     */
                    const T& operator[](size_t index){
                    if (index<0 || index>this->sortedElements.size())
                    {
                        throw std::out_of_range("Index is invalid, try again!");
                    }
                    else{
                        return (this->sortedElements[index]);
                    }

                    }
        };

        ReverseOrder begin_reverse_order() const { return ReverseOrder(*this,0); }
        ReverseOrder end_reverse_order() const { return ReverseOrder(*this,this->elements.size()); }


        class Order{

            private:
                        std::vector<T> sortedElements;
                        size_t indexOfElements;

            public: 
                    Order(const MyContainer& container, size_t initialize_Index): sortedElements(container.elements), indexOfElements(initialize_Index){}

                     
                    /**
                     * @brief operator* , for dereferencing and accssing elements in the container.
                     *
                     * 
                     *
                     * 
                     * 
                     * @return the element in the sortedelement container.
                     */
                     const T& operator*()const{
                        return sortedElements[indexOfElements];
                     }


                    /**
                     * @brief operator for pre increment of the container.
                     *
                     * 
                     *
                     * 
                     * @return increments and returns the value of this.
                     */
                     Order& operator++(){
                        ++indexOfElements;
                        return (*this);

                     }
                     /**
                     * @brief operator == , to check if to containers are equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */   
                     const bool operator==(const Order& other)const{
                        return(this->indexOfElements == other.indexOfElements);
                     }
                     /**
                     * @brief operator != , to check if to containers are not equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */   
                     const bool operator!=(const Order& other)const{
                        return!(this->indexOfElements == other.indexOfElements);
                     }
                      /**
                     * @brief operator[] for accessing an element in the container through an index.
                     *
                     * 
                     *
                     * @param index index of users choice , as long as it exists.
                     * 
                     * @return The element in the container corresponding to the index if it exists.
                     */   
                     const T& operator[](size_t index){
                    if (index<0 || index>this->sortedElements.size())
                    {
                        throw std::out_of_range("Index is invalid, try again!");
                    }
                    else{
                        return (this->sortedElements[index]);
                    }

                    }
                    
        };

         Order begin_order() const { return Order(*this,0); }
         Order end_order() const { return Order(*this,this->elements.size()); }

        class MiddleOutOrder{

            private:
                    std::vector<T> sortedElements;
                    size_t indexOfElements;

            public:
                    MiddleOutOrder(const MyContainer& container,size_t initialize_Index):indexOfElements(initialize_Index){
                        
                        
                         std::vector<T> sorted = container.getElements();
                         if (sorted.empty()) return;

                             int middle = static_cast<int>(sorted.size()/2);
                             sortedElements.push_back(sorted[middle]);
                             int left = middle-1;
                             int right = middle+1;
                             while (left>=0||right<sorted.size())
                             {
                                if (left>=0)
                                {
                                    sortedElements.push_back(sorted[left]);

                                    --left;
                                }

                                if (right<sorted.size())
                                {
                                    sortedElements.push_back(sorted[right]);
                                    ++right;
                                    
                                }
                                
                                
                             }
                             
                    }

                    /**
                     * @brief operator* , for dereferencing and accssing elements in the container.
                     *
                     * 
                     *
                     * 
                     * 
                     * @return the element in the sortedelement container.
                     */
                    const T& operator*() const{
                        return sortedElements[indexOfElements];
                    }
                    /**
                     * @brief operator for pre increment of the container.
                     *
                     * 
                     *
                     * 
                     * @return increments and returns the value of this.
                     */
                    MiddleOutOrder& operator++(){
                        ++indexOfElements;
                        return(*this);
                    }
                    /**
                     * @brief operator == , to check if to containers are equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */ 
                    const bool operator==(const MiddleOutOrder& other)const{
                        return(this->indexOfElements==other.indexOfElements);
                    }
                    /**
                     * @brief operator != , to check if to containers are not equal.
                     *
                     * 
                     *
                     * @param other another container of the same type.
                     * 
                     * @return return if they are equal or not
                     */ 
                    const bool operator!=(const MiddleOutOrder& other)const{
                        return!(this->indexOfElements==other.indexOfElements);
                    }

                     /**
                     * @brief operator[] for accessing an element in the container through an index.
                     *
                     * 
                     *
                     * @param index index of users choice , as long as it exists.
                     * 
                     * @return The element in the container corresponding to the index if it exists.
                     */   
                    const T& operator[](size_t index){
                    if (index<0 || index>this->sortedElements.size())
                    {
                        throw std::out_of_range("Index is invalid, try again!");
                    }
                    else{
                        return (this->sortedElements[index]);
                    }

                    }
                  
       };

        MiddleOutOrder begin_middle_out_order() const { return MiddleOutOrder(*this,0); }
        MiddleOutOrder end_middle_out_order() const { return MiddleOutOrder(*this,this->elements.size()); }
    
 };

template <typename T>



 /**
* @brief implementation of the friend function to print the container.
*
* 
*
* @param os os stream.
* @param container container of type T.
* @return os object.
*/   
std::ostream &operator<< (std::ostream& os, const MyContainer<T>& container){
    os<<"[ " ;
    for (size_t i = 0; i < container.size(); ++i)
    {

        os<< container.elements[i]<<" ";
        
    }
    os<< "]" << std::endl;
    return os;
    
}

}
