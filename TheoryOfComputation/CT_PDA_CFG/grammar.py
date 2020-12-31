from pushdownAutomaton import *
import copy

class Grammar:
    """Object that contains all grammar rules for a language"""
    def __init__(self, PA = None):
        self.grammar_rules_list = []
        if(PA != None):
            #generate all rules for the first step
            print("From step 1 ...")
            for s in PA.F:
                new_grammar_rule = GrammarRule(["S"],[[PA.I,"l",s]])
                self.add_grammar_rule(new_grammar_rule)
                print(str(new_grammar_rule.A) +"->"+ str(new_grammar_rule.B))
            
            print("From step 2 ...")
            for s in PA.S:
                new_grammar_rule = GrammarRule([s,"l",s],["l"])
                self.add_grammar_rule(new_grammar_rule)
                print(str(new_grammar_rule.A) +"->"+ str(new_grammar_rule.B))

            print("From step 3 ...")
            for transition in PA.E:
                if transition[2] != "l":
                    p = transition[0]
                    x = transition[1]
                    y = transition[2]
                    q = transition[3]
                    z = transition[4]
                    for s in PA.S:
                        new_grammar_rule = GrammarRule([p,y,s],[x,[q,z,s]])
                        self.add_grammar_rule(new_grammar_rule)
                        print(str(new_grammar_rule.A) +"->"+ str(new_grammar_rule.B))
            
            print("From step 4 ...")
            for transition in PA.E:
                if transition[2] == "l":
                    print("From transition" +str(transition) + "\n")
                    p = transition[0]
                    x = transition[1]
                    y = transition[2]
                    q = transition[3]
                    z = transition[4]
                    for w in PA.stack_symbols:
                        for r in PA.S:
                            for k in PA.S:
                                new_grammar_rule = GrammarRule([p,w,r],[x,[q,z,k],[k,w,r]])
                                self.add_grammar_rule(new_grammar_rule)
                                print(str(new_grammar_rule.A) +"->"+ str(new_grammar_rule.B))
                        print("\n")
    
    def add_grammar_rule(self,rule):
        self.grammar_rules_list.append(rule)
    
    def asdict(self):
        rules_as_list = []
        for r in self.grammar_rules_list:
            rules_as_list.append([r.A,r.B])
        d = {"grammar_rules_list": rules_as_list}
        #print(str(d))
        return d
    
    def import_rules(self, rules_list):
        for r in rules_list:
            #print(str(r[0]) + " -> " +str(r[1]))
            new_rule = GrammarRule(r[0],r[1])
            self.add_grammar_rule(new_rule)

    def evaluate_string(self, s):
        #find initial rule
        result=[False,[],[]]
        for r in self.grammar_rules_list:
            if(r.A == ["S"]):
                #print(str(r.A) + " -> "+ str(r.B))
                result = self.evaluate_rule(r,s)
                if result[0] == True:
                    result[2].insert(0,r)
        return result

    def evaluate_rule(self, r, s):
        non_terminal_found = False
        result = [False, [],[]]
        #Find next triplet in B rule
        #print("string len: "+ str(len(s)))
        for i in range(len(r.B)):
            if (isinstance(r.B[i], list)):
                non_terminal_found = True
                t = r.B[i]
                for grammar_rule in self.grammar_rules_list:
                    if grammar_rule.A == t:
                        #print("Current rule..."+ str(t))
                        #print(str(r.A) + " -> "+ str(r.B))
                        #print("Possible grammar rule that can be used ...")
                        #print(str(grammar_rule.A) + " -> "+ str(grammar_rule.B))
                        #discard rule if there is character to be read is not the next in string
                        if(len(grammar_rule.B) == 3):
                            #if (len(s) == 0):
                            #    print("discard rule, no remaining characters")

                            if ((len(s) > 0) and (grammar_rule.B[0] == s[0])):
                                #print("same character")
                                rule_for_evaluation = copy.deepcopy(r)
                                #print("new copy: " + str(rule_for_evaluation.A) + "->" + str(rule_for_evaluation.B))
                                #print("index to be deleted = " + str(i))
                                del rule_for_evaluation.B[i]
                                rule_for_evaluation.B.insert(i,grammar_rule.B[2])
                                rule_for_evaluation.B.insert(i,grammar_rule.B[1])
                                rule_for_evaluation.B.insert(i,grammar_rule.B[0])
                                #print(" after: " + str(rule_for_evaluation.A) + "->" + str(rule_for_evaluation.B))
                                result = self.evaluate_rule(rule_for_evaluation,s[1:])
                                if result[0] == True :
                                    result[1].insert(0,grammar_rule)
                                    result[2].insert(0,rule_for_evaluation)
                                    #print("positive result: " + str(result))
                                    break
                            elif (grammar_rule.B[0] == 'l'):
                                rule_for_evaluation = copy.deepcopy(r)
                                #print("( l )new copy: " + str(rule_for_evaluation.A) + "->" + str(rule_for_evaluation.B))
                                #print("index to be deleted = " + str(i))
                                del rule_for_evaluation.B[i]
                                rule_for_evaluation.B.insert(i,grammar_rule.B[2])
                                rule_for_evaluation.B.insert(i,grammar_rule.B[1])
                                #rule_for_evaluation.B.insert(i,grammar_rule.B[0])
                                #print(" after: " + str(rule_for_evaluation.A) + "->" + str(rule_for_evaluation.B))
                                result = self.evaluate_rule(rule_for_evaluation,s)
                                if result[0] == True :
                                    result[1].insert(0,grammar_rule)
                                    result[2].insert(0,rule_for_evaluation)
                                    break
                            #else:
                            #    print("rule discarted due to character")
                        if(len(grammar_rule.B) == 2):
                            #if (len(s) == 0):
                            #    print("discard rule, no remaining characters")

                            if ((len(s) > 0) and ((grammar_rule.B[0] == s[0]))):
                                #print("same character")
                                rule_for_evaluation = copy.deepcopy(r)
                                #print("new copy: " + str(rule_for_evaluation.A) + "->" + str(rule_for_evaluation.B))
                                #print("index to be deleted = " + str(i))
                                del rule_for_evaluation.B[i]
                                rule_for_evaluation.B.insert(i,grammar_rule.B[1])
                                rule_for_evaluation.B.insert(i,grammar_rule.B[0])
                                #print(" after: " + str(rule_for_evaluation.A) + "->" + str(rule_for_evaluation.B))
                                result = self.evaluate_rule(rule_for_evaluation,s[1:])
                                if result[0] == True :
                                    result[1].insert(0,grammar_rule)
                                    result[2].insert(0,rule_for_evaluation)
                                    break
                            elif (grammar_rule.B[0] == 'l'):
                                rule_for_evaluation = copy.deepcopy(r)
                                #print("( l )new copy: " + str(rule_for_evaluation.A) + "->" + str(rule_for_evaluation.B))
                                #print("index to be deleted = " + str(i))
                                del rule_for_evaluation.B[i]
                                rule_for_evaluation.B.insert(i,grammar_rule.B[1])
                                #rule_for_evaluation.B.insert(i,grammar_rule.B[0])
                                #print(" after: " + str(rule_for_evaluation.A) + "->" + str(rule_for_evaluation.B))
                                result = self.evaluate_rule(rule_for_evaluation,s)
                                if result[0] == True :
                                    result[1].insert(0,grammar_rule)
                                    result[2].insert(0,rule_for_evaluation)
                                    break

                        if(len(grammar_rule.B) == 1):
                            #print("index to be deleted = " + str(i))
                            rule_for_evaluation = copy.deepcopy(r)
                            del rule_for_evaluation.B[i]
                            if grammar_rule.B[0] != 'l': 
                                rule_for_evaluation.B.insert(i,grammar_rule.B[0])
                            result = self.evaluate_rule(rule_for_evaluation,s)
                            if result[0] == True :
                                    result[1].insert(0,grammar_rule)
                                    result[2].insert(0,rule_for_evaluation)
                                    break
                break #stop evaluating the rest of non-terminan values 
        if( len(s) == 0 and non_terminal_found == False):
            print("eureka! ")
            result = [True, [],[]]
        return result

class GrammarRule:
    """Object that contains a grammar production rule"""
    def __init__(self,A,B):
        #A -> B
        #Where:
        # A - Non terminal symbol
        self.A = A
        # B - combination of terminal or Non-terminal symbols
        self.B = B

