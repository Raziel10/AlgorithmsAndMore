import json 
from pushdownAutomaton import *
from grammar import *
import sys

#Script that generates a grammar based in a PushdownAutomaton
#Author Raziel Lopez Escamilla

#take file name from first parameter
Pushdown_Automaton_File_Name = sys.argv[1]
Grammar_output_file_name = sys.argv[2]
def pushdown_automaton_to_grammar():
    with open(Pushdown_Automaton_File_Name) as f:
        data = json.load(f)
        PA = PushdownAutomaton(data["S"],data["F"],data["I"],data["E"])
        G = Grammar(PA)
        grammar_json = json.dumps(G.asdict())

        firstB = False
        Bcount = 0
        # Writing to sample.json 
        #before wrinting file add format
        c = 0
        while c < len(grammar_json): 

            if grammar_json[c] == ":":
                new_grammar_json = grammar_json[:c+1] +"\n   "+ grammar_json[c+1:]
                grammar_json = new_grammar_json 
            if grammar_json[c] == "[":
                if firstB == False:
                    new_grammar_json = grammar_json[:c+1] +"\n    "+ grammar_json[c+1:]
                    grammar_json = new_grammar_json
                    firstB = True
                else:
                    Bcount = Bcount +1
            if grammar_json[c] == "]":
                if (firstB == True) and (Bcount == 0):
                    new_grammar_json = grammar_json[:c] +"\n   ]\n"+ grammar_json[c+1:]
                    grammar_json = new_grammar_json
                Bcount = Bcount - 1

            if grammar_json[c] == ",":
                if (firstB == True) and (Bcount == 0):
                    new_grammar_json = grammar_json[:c+1] +"\n   "+ grammar_json[c+1:]
                    grammar_json = new_grammar_json
                
            c = c +1
                    
        #write file
        with open(Grammar_output_file_name, "w") as outfile: 
            outfile.write(grammar_json) 
"""
def read_grammar():
     with open(Grammar_output_file_name) as f:
        data = json.load(f)
        print(data["grammar_rules_list"])"""


pushdown_automaton_to_grammar()

#read_grammar()

