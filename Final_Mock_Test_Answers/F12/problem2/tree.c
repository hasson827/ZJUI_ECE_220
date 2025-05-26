#include <stdlib.h>
#include "tree.h"

/* Counte the number of negative values stored in a tree */
int countNegatives(struct node* root)
{
   /* Implement Me */
   if (root == NULL){
      return 0;
   }else{
      int count = 0;
      if (root->data < 0){
         count = 1;
      }
      return count + countNegatives(root->left) + countNegatives(root->right);
   }
   return 0;
}
