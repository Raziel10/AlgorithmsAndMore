import json 
from pushdownAutomaton import *
from grammar import *
import sys

#Script that evaluates a grammar with an specific string
#To work properly, a grammar file name must be passed as argument to script
#Author: Raziel Lopez Escamilla

#take grammar file name from first parameter
grammar_file_name = sys.argv[1]
#read string for evaluation
string_for_evaluation = sys.argv[2]

def grammar_evaluation():
    print("Grammar File name: " + grammar_file_name)
    print("String for evaluation: " + string_for_evaluation)
    with open(grammar_file_name) as f:
        data = json.load(f)
        G = Grammar()
        print("Importing rules from "+ grammar_file_name +" ...")
        G.import_rules(data["grammar_rules_list"])
        print("evaluating input , this might take a while ...")
        result = G.evaluate_string(string_for_evaluation)
        if result[0] == True:
            print("lambda = 'l' ")
            print("Initial rule:")
            print(str(result[2][0].A) + " -> " + str(result[2][0].B))
            for i in range(len(result[1])):
                print("rule used:" )
                print("\t" + str(result[1][i].A) + " -> " + str(result[1][i].B))
                print("substitution:")
                print(str(result[2][i+1].A) + " -> " + str(result[2][i+1].B))
        else:
            print("String not valid for this grammar rules")
        
grammar_evaluation()

