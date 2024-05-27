# plan:
* Parse names of functioins that we mustn't change from https://documentation.help/CppReference/all_cpp_functions.html
* Ask what the user wants to change
* If it is change private fields than do it
* Else we ask what style they want to get
* Ask if they want to change existing files or make new
* Traverse all files for searching all the definitions of the things that user wants to change
* Add the func/class/var(depending on what user wants) names to a set
* Traverse all files, deviding every word and checking if the word in our set
* Then if it is, we change it
