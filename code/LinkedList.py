class Node:
    def __init__(self,value):
        self.value=value
        self.next=None
        
    def traversal(self):
        temp=self
        while(temp):
            print(temp.value,end=" ")
            temp=temp.next
            
    def len(self):
        length=0
        temp=self
        while(temp):
            length+=1
            temp=temp.next
        print(length)
        
    def front_insertion(self,data):
        new_node=Node(data)
        if self:
            new_node.next=self
            return new_node
             
        else:#None
            return new_node
            
    def back_insertion(self,data):       
        new_node=Node(data)
        
        if self:
            self.next=new_node
            return self
        else:
            return new_node
    
    def updateNode(self, val, index):
        if self is None:
            print("empty")
        temp=self
        
        for i in range(index):
            temp=temp.next 
        temp.value=val
        temp=self
        return temp   
    
    def delete_front(self):
        if self is None:
            return 
        else:
            self=self.next
            return self
        
    def delete_back(self):
        if self is None:
            return 
        else:
            temp=self
            while(temp.next.next):
                temp=temp.next
            temp.next=None
            temp=self
            return temp
                
head=Node(1)
head.next=Node(4)
head.next.next=Node(11)
# head.traversal()
# head=head.back_insertion(4)
head=head.updateNode(90, 0)
# head.traversal()
head=head.delete_back()
head.traversal()
# head.next=Node(2)    
# head.next.next=Node(3)  