//Maintain a pool (cache) of reusable objects that are expensive to create like DB connections, threads, sockets, game entities
//
// Advantages:
// - Reduces creation/destruction overhead for expensive objects
// - Efficient resource reuse
// - Limits number of active resources
//
// Disadvantages:
// - More complex management logic
// - Must handle ownership and resource state carefully
//
#include<iostream>
#include<vector>
#include<memory>

class Resource{
    private:
        int m_id;
    public:
        Resource(int id):m_id(id){
            std::cout<<"Creating resource"<<std::endl;
        }
};

class ResourcePool{
    private:
        std::vector<std::unique_ptr<Resource>> resources;
    public:
        ResourcePool(int size){
            for(int i=0;i<size;i++){
                resources.push_back(std::make_unique<Resource>(i));
            }
        }
        std::unique_ptr<Resource> acquireResource(){
            if(resources.empty()){
                std::cout<<"No resources available"<<std::endl;
                return nullptr;
            }
            std::unique_ptr<Resource> res = std::move(resources.back());
            resources.pop_back();
            return res;
        }
        void releaseResource(std::unique_ptr<Resource> res){
            resources.push_back(std::move(res));
        }
};



int main(){
    ResourcePool pool(3);
    
    auto res1 = pool.acquireResource();
    auto res2 = pool.acquireResource();
    auto res3 = pool.acquireResource();
    auto res4 = pool.acquireResource(); // No resources available
    if(!res4){
        std::cout<<"All resources are occupied"<<std::endl;
    }
    pool.releaseResource(std::move(res1)); // Release res2 back to pool
    res4 = pool.acquireResource(); // Should acquire res2 again
    if(res4){
        std::cout<<"Acquired a resource after releasing one"<<std::endl;
    }
    pool.releaseResource(std::move(res2));
    pool.releaseResource(std::move(res3));
    pool.releaseResource(std::move(res4));
    return 0;
}