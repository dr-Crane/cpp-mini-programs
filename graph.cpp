#include <iostream>

using namespace std;
struct trailer;


struct leader
{
    int key;
    int st;
    trailer *list;
    leader *nextlead;
};

struct trailer
{
    leader *vert;
    trailer *next;
};

bool circle_exist (leader *graph, int vx, int vy, int vz)
{
    if(vx<0||vy<0||vz<0) 
    {
        cout<<"Vertex doesn't exist"<<endl;
        return false;
    }

    bool chek = false;

    leader *space = graph;

    int num = 0;
    while(space)
    {
        num++;
        space = space->nextlead;
    }

    if(vx>num||vy>num||vz>num)
    {
        return false;
    }

    leader *ptrVX = nullptr;
    leader *ptrVY = nullptr;
    leader *ptrVZ = nullptr;

    for(int i=0; i<vx; i++)
    {
        ptrVX = space->nextlead;
        space = space->nextlead;
    }
    for(int i=0; i<vy; i++)
    {
        ptrVY = space->nextlead;
        space = space->nextlead;
    }    
    for(int i=0; i<vz; i++)
    {
        ptrVZ = space->nextlead;
        space = space->nextlead;
    }

    if(ptrVX->st==0||ptrVY->st==0||ptrVZ->st==0)
    {
        return false;
    }

    leader *tmpVX = ptrVX;

    trailer *list_1 = tmpVX->list;
    

    while(list_1)
    {
        if(list_1->vert == ptrVY || list_1->vert == ptrVZ)
        {
            leader *tmpVY = list_1->vert;
            trailer *list_2 = tmpVY->list;
            while(list_2)
            {
                if(list_2->vert == ptrVX)
                {
                    return true;
                }
                if(list_2->vert == ptrVZ)
                {
                    leader *tmpVZ = ptrVZ;
                    trailer *list_3 = tmpVZ->list;
                    while(list_3)
                    {
                        if(list_3->vert==ptrVX)
                        {
                            return true;
                        }
                        list_3 = list_3->next;
                    }
                }
                    list_2 = list_2->next;
            }
        }
        list_1 = list_1->next;
    }


    return false;

}



int main()
{
    
    

}
