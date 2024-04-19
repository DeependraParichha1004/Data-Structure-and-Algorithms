from collections import deque
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
        print(root.value, end=" "),
 
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
    
def level_order_traversal(root):
    h=height(root) 
    even=False
    odd=False
    for i in range(1,h+1):
        if(i%2==0):
            even=current_level_order_traversal(root,i)
            print(even)
        if(i%2!=0):
            odd=current_level_order_traversal(root,i)
    # return even,odd
            
        
                 
def current_level_order_traversal(root,level):
    if root is None:
        return 
    if level%2==0:
        return root.value
    
    if level%2!=0:
        return root.value
    else:
        current_level_order_traversal(root.left,level-1)
        current_level_order_traversal(root.right,level-1)
        
def queue_level_order(root):
    # if root is None:
    #         return
    queue=deque()
    queue.append(root)
    while(len(queue)>0):
        print(queue[0].value,end=" ")
        node=queue.popleft()
        if node.left is not None:
            queue.append(node.left)
        if node.right is not None:
            queue.append(node.right)
         
        
def check_even_odd(root):
    queue=deque()
    queue.append(root)
    level=0
    while(len(queue)>0):
        
        
        for i in range(len(queue)):
            node=queue[0]
            queue.popleft()
            
            if(level%2==0):#even
                if(node.value%2==0):
                    return False
            elif level%2!=0:
                if(node.value%2==1):
                    return False
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        level+=1
    return True

def successor(root,val):
    succ=None
    while(root!=None):
        if(root.value<=val):
            root=root.right
        elif(root.value>val):
            succ=root
            root=root.left
    if succ is not None:
        return succ.value
    else:
        return None

def predecessor(root,val):
    pred=None
    while(root!=None):
        if(root.value>=val):
            root=root.left
        elif(root.value<val):
            pred=root
            root=root.right
    return pred.value
          

def a(root):
    queue=deque()
    queue.append(root)
    while(len(queue)>0):
        
        print(queue[0].value,end=" ")
        node=queue.popleft()

        if(node.left is not None):
            queue.append(node.left)
        if(node.right is not None):
            queue.append(node.right)  
root1=Node(5)
root1.left=Node(3)
root1.right=Node(7)
root1.left.left=Node(2)
root1.left.right=Node(4)
root1.right.right=Node(9)
root1.right.right.left=Node(8)
root1.right.right.right=Node(10)

root2=Node(1)
root2.left=Node(2)
root2.right=Node(3)
root2.right.left=Node(4)
root2.right.right=Node(5)

# i=10
# print(predecessor(root1,i))
# print(successor(root1,i))

# level_order_traversal(root1)
# if (check_even_odd(root1)):
#         print("YES")
# else: 
#     print("NO")

a(root2)