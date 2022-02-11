//1ST DATA STRUCTURES AND ALGORITHMS EVALUATION
#include<stdio.h>
#include<stdlib.h>
     
typedef struct sensor
{
    int sensor_id;
    float time_stamp;
    float heat_value;
    struct sensor *left,*right;
}*sensor;

sensor Create(int sensor_id,float time_stamp, float heat_value)
{
    sensor var;
    var=(struct sensor*)malloc(sizeof(struct sensor));
    var->left=NULL;
    var->right=NULL;
    
    var->sensor_id=sensor_id;
    var->time_stamp=time_stamp;
    var->heat_value=heat_value;
    return var;
}

sensor insert(sensor root,int sensor_id,float time_stamp,float heat_value)
{
    if(root==NULL)
    {
        root = Create(sensor_id,time_stamp,heat_value);
        return root;
    }
    else if (root->heat_value>heat_value)
    {
        root->left= insert(root->left,sensor_id,time_stamp,heat_value);
    }
    else if(root->heat_value<heat_value)
    {
        root->right= insert(root->right,sensor_id,time_stamp,heat_value);
    }
    return root;

}
sensor search(sensor root, int key){
    while(root!=NULL){
        if(key == root->heat_value){
            return root;
        }
        else if(key<root->heat_value){
            root = root->left;
        }
        else if(key>root->heat_value)
        {
            root = root->right;
        }
        else{
            printf("Element not found\n");
        }

    }
    return NULL;
}
void inorder(sensor root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("Sensor ID : %d\n",root->sensor_id);
        printf("time stamp : %f\n",root->time_stamp);
        printf("heat value : %f\n",root->heat_value);
        inorder(root->right);
    }
}
void preorder(sensor root)
{
    if(root!=NULL)
    {

       
        printf("Sensor ID : %d\n",root->sensor_id);
        printf("time stamp : %f\n",root->time_stamp);
        printf("heat value : %f\n",root->heat_value);
         preorder(root->left);
        preorder(root->right);
        
    }
}
void postorder(sensor root)
{
    if(root!=NULL)
    {
          postorder(root->left);
          postorder(root->right);
        printf("Sensor ID : %d\n",root->sensor_id);
        printf("Time Stamp : %f\n",root->time_stamp);
        printf("Heat value : %f\n",root->heat_value);
       

    }
}
sensor delete(sensor root,int heat_value)
{
    if(root==NULL)
    {
        printf("empty\n");
    }
    sensor cur,par,p,suc;
    cur=root;
    par=NULL;
    while(cur!=NULL&&cur->heat_value!=heat_value)
    {
        par=cur;
        if(heat_value>cur->heat_value)
            cur=cur->right;
        else if(heat_value<cur->heat_value)
            cur=cur->left;

    }
    if(cur->left==NULL)
        p=cur->right;
    else if(cur->right==NULL)
        p=cur->left;
    else
    {
        suc=cur->right;
        while(suc->left!=NULL)
        {
            suc=suc->left;
        }
        suc->left=cur->left;
        p=cur->right;
    }
    if(par==NULL)
    {
        free(cur);
        return root;
    }
    if(cur==par->left)
        par->left=p;
    else if(cur==par->right)
        par->right=p;

    free(cur);
    return root;
}
sensor level(sensor root,float heat_value)
{
    int lvl=0;
    if(root==NULL)
    {
        printf("this is empty\n");
    }
    if(root->heat_value==heat_value)
    {
        lvl=0;
    }
    else
    {
        sensor cur,par,n;
        cur=root;
        par=NULL;
        while(cur!=NULL&&cur->heat_value!=heat_value)
        {
            lvl++;
            if(cur->heat_value>heat_value)
                cur=cur->left;
            else if(cur->heat_value<heat_value)
                cur=cur->right;
        }
    }
    printf("Level of heat node is %d\n",lvl);
    return root;
}
void ancestors(sensor root,int heat_value)
{
    if(root==NULL)
    {
        printf("this is empty");
    }
    else
    {
        sensor cur,par,n;
        cur=root;
        printf("ancestors of given id are\n");
        while(cur!=NULL&&cur->heat_value!=heat_value)
        {

            printf("Sensor ID : %d\n",cur->sensor_id);
            printf("Time stamp : %f\n",cur->time_stamp);
            printf(" Heat valve: %f\n",cur->heat_value);
            
            if(cur->heat_value>heat_value)
                cur=cur->left;
            else if(cur->heat_value<heat_value)
                cur=cur->right;
        }

    }
}
void lrsubtree(sensor root)
{ int l=0,r=0;
    sensor cur;
    cur=root;
    while(cur!=NULL)
    {
        l++;
        cur=cur->left;
    }
        cur=root;
    while(cur!=NULL)
    {
        r++;
        cur=cur->right;
    }
    if(r>l)
        printf("Right tree is largest\n");
    else if(l>r)
        printf("Left tree is largest\n");
    else
        printf("Tree is balanced tress\n");
}int max=0;

sensor leftrigtsub(sensor root,int heat_value)
{

    if(root->heat_value==heat_value)
    {
        inorder(root->left);
        inorder(root->right);
    }


    else if(root->heat_value>heat_value)
        root->left=leftrigtsub(root->left,heat_value);
    else if(root->heat_value<heat_value)
        root->right=leftrigtsub(root->right,heat_value);
    return root;
}
void highest(sensor root,float heat_value)
{
    if(root==NULL)
    {
        printf("no element:");

    }
    while(root->right!=NULL)
    {
        
        root =root->right;
        

    }
    printf("max : %f\n",root->time_stamp);
}

sensor threshod(sensor root, float tree)
{
    if(root!=NULL)
    {
        threshod(root->left,tree);
        if(root->heat_value>tree)
        
            printf("display time stamp greater:%f\n",root->time_stamp);
            
        
         threshod(root->right,tree);
       
    }
}



int main(){
    int ch;
          sensor root= NULL;
           int sensor_id;


    float time_stamp;
    float heat_value;
    float sercid;
    float del;
    float lev;
    float anc;
    float rsl;
    float tree;

          while(1)
          {
              printf("Enter 1 to insert:\n");
              printf("Enter 2 to search:\n");
              printf("Enter 3 for inorder traversal:\n");
              printf("Enter 4 for Preorder traversal:\n");
              printf("Enter 5 for Postorder traversal:\n");
              printf("Enter 6 for delete:\n");
              printf("Enter 7 for displaying level:\n");
              printf("Enter 8 for ancestors:\n");
              printf("Entr  9 for largest subtree:\n");
              printf("Entr  10 for left right:\n");
              printf("Entr  11 for highest:\n");
              printf("enter 12 for threshold:\n");


              scanf("%d",&ch);

              switch(ch)
              {
                  {
                  case 1 : printf("Enter sensor ID\n");
                           scanf("%d",&sensor_id);
                           printf("Enter time stamp ID\n");
                           scanf("%f",&time_stamp);
                           printf("Enter heat value\n");

                           scanf("%f",&heat_value);

                           root= insert(root,sensor_id,time_stamp,heat_value);
                           break;
                  }
                  {
                      case 2:  printf("enter the number to search\n");
                              scanf("%f",&sercid);
                              root=search(root,sercid);
                             printf("element found:%f\n",sercid);
                               break;

                  }
                  {
                      case 3: printf("InOrder Traversal\n");
                              inorder(root);
                              break;
                         {
                      case 4: printf("PreOrder Traversal\n");
                             preorder(root);

                             break;
                        }
                    {
                      case 5: printf("PostOrder Traversal\n");
                             postorder(root);
                             break;
                    }
                    { case 6: printf("enter heat value to delete");
                           scanf("%f",&del);
                           root=delete(root,del);
                    
                             break;
                           }
                    {
                      case 7: printf("Enter heat value to diplay its level\n");
                              scanf("%f",&lev);
                              root=level(root,lev);
                              break;
                        
                    }
                    {
                      case 8: printf("Enter the heat value to print its ancestors\n");
                              scanf("%f",&anc);
                              ancestors(root,anc);
                              break;
                    }
                    {
                      case 9: {
                                lrsubtree(root);
                                   break;
                               }
                  {
                    case 10:
                         {
                         printf("Heat value to PRint left and right subtree");
                         scanf("%f",&rsl);
                         root=leftrigtsub(root,rsl);
                         break;
                         }
                         {
                    case 11: highest(root,tree);
                             break;
                         }
                         {
                    case 12: printf("enter the heat value\n");
                         scanf("%f",&tree);
                         threshod(root,tree);
                         break;
                         }

        } 
                    }

                
                  }
              }

          }


   
}