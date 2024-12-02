class Stack:
    def _init_(self):
        self.stack = []
        
    def push(self, value):
        self.stack.append(value)
        print(f"{value} pushed to the stack.")

    def pop(self):
        if not self.is_empty():
            value = self.stack.pop()
            print(f"{value} popped from the stack.")
            return value
        else:
            print("Stack is empty! Cannot pop.")
            return None

    def is_empty(self):
        return len(self.stack) == 0

    def display(self):
        if self.is_empty():
            print("Stack is empty.")
        else:
            print("Current stack:", self.stack)

if _name_ == "_main_":
    s = Stack()
    s.push(10)
    s.push(20)
    s.push(30)
    
    s.display()
    
    s.pop()
    s.display()

    s.pop()
    s.pop()
    s.pop()