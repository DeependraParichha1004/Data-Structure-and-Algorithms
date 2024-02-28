class Node:
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None
        

def height(root):
    
    if(root==None):
        return 0
    
    lheight=height(root.left)
    rheight=height(root.right)
    
    if(lheight<rheight):
        return rheight+1
    else:
        return lheight+1

def level_order_traversing(root):
    h=height(root)
    
    for i in range(1,h+1):
        level_order(root,i)
        
def level_order(root,level):
    if root==None:
        return 
    if level==1:
        return root.value
    elif(level>1):
        level_order(root.left,level-1)
        level_order(root.right,level-1)
    
    
def similar(root1,root2):
    h1=height(root1)
    h2=height(root2)
    
    if(h1==h2):
        for i in range(1,h1+1):
            if level_order(root1,h1)!=level_order(root2,h2):
                return False
    return True

def preorder_traversing(root):
    h=height(root)
    
    for i in range(1,h+1):
        printPreorder(root,i)
        
def printPreorder(root):
 
    if root:
 
        # First print the data of node
        print(root.val, end=" "),
 
        # Then recur on left child
        printPreorder(root.left)
 
        # Finally recur on right child
        printPreorder(root.right)
        
              
def Identical(root1,root2):
    if (root1==None) & (root2==None):
        return True
 
    if (root1!=None) & (root2!=None):
 
        return ((root1.value!=root2.value) and
        Identical(root1.left,root2.left)and
        Identical(root1.right,root2.right))
        
    else:
        return False
            
def morris_traversal(root):
    current = root   
    
    while(current):
        if current.left is None:
            print(current.value,end=" ")
            current = current.right
        else:
            pre=current.left
            
            while(pre.right and pre.right!=current):
                pre=pre.right
                
            if pre.right is None:
                pre.right=current
                current = current.left
            else:
                pre.right=None
                print(current.value,end=" ")
                current = current.right  
    
            
    
root1=Node(1)
root1.left=Node(2)
root1.right=Node(3)
root1.left.left=Node(4)
root1.left.right=Node(5)

root2=Node(1)
root2.left=Node(2)
root2.right=Node(3)
root2.right.left=Node(4)
root2.right.right=Node(5)

morris_traversal(root1)