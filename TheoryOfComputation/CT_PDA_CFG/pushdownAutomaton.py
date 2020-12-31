
class PushdownAutomaton:
    """A Pushdown automaton class"""
    def __init__(self,S,F,I,E):
        self.S = S
        self.F = F
        self.I = I
        self.E = E
        self.stack_symbols = set()

        for transition in E:
            self.stack_symbols.add(transition[2])
            
    
    
            

