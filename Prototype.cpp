
// Prototype Design Pattern
// Allows creating new objects by copying existing ones (cloning), instead of creating from scratch.
// Ex: if you want to create Non Playable characters (NPCs) in a game that have similar behaviour, and they have costly initialization, 
//you can create one NPC and clone it to create more with different IDs.
//
// Advantages:
// - Avoids costly creation logic for new objects
// - Can clone complex objects easily
// - Flexible for runtime object creation
//
// Disadvantages:
// - Requires correct implementation of copy constructor
// - Can be tricky with deep copies or pointer members

#include <iostream>
#include <vector>
#include <memory>

class NPC{
    public:
        int m_id;
        int m_character; //Assume it is a constly variable to create
        NPC(int m_id=0):m_id(m_id){
            std::cout<<"Doing some costly operation to create m_character"<<std::endl;
            m_character=100;
        }
        std::unique_ptr<NPC> clone(int m_id =-1){
            std::unique_ptr<NPC> cloned=std::make_unique<NPC>(*this);
            cloned->m_id = m_id;
            std::cout<<"Cloning NPC with id: "<<m_id<<std::endl;
            return cloned;
        }
        NPC(const NPC& other){
            m_id=-1;
            m_character=other.m_character;
        }
};

int main(){
    std::unique_ptr<NPC> npc1 = std::make_unique<NPC>(0);
    std::vector<std::unique_ptr<NPC>> npcs;
    for(int i=1;i<6;i++){
        npcs.push_back(npc1->clone(i));
    }
    return 0;
}