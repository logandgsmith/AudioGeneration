COP3503 Group 9 Project Style Guide
==========================================
_Largely derived from [Google C++ Style Guide naming](https://google.github.io/styleguide/cppguide.html#Naming) (with some modifications)_

## General Naming Rules

* Names should be descriptive; avoid abbreviation.
* Give as descriptive a name as possible, within reason. Do not worry about saving horizontal space as it is far more important to make your code immediately understandable by a new reader.

### File Names

Keep file names all lowercase with underscores between words

### Classes, Structs, Enums, & Type Template Paramaters

* Use UpperCamelCase (aka PascalCase).  
* Capitalize every word

### Variable Names

* Typically, use all lowercase characters
* Use underscores between words in a name
* **Class** data members have an additional underscore after the name
* **Struct** data members follow normal naming rules, however
* **const** (constants) use CamelCase with a k in front (ex. kMyConstant)

### Function Names

Use lowerCamelCase for function names

### Namespace Names

Use all lowercase characters

### Enumerator Names

Follow the same rules as for **const** variables


## Structure Rules
How to structure your code

### Parameters
 **Ex.** `void exampleFunction(int intVal, double dblVal, std::string stringVal, ClassName objVal)`

* When writing parameters put numerical values (like `int` or `double`) before `string` values
* Values other than numerical and `string` should be after the `string` values

### Header Files

* Use `#pragma once` at the top of your file instead of regular include guards
* List `public` functions before `private` fields
* Write the Constructor before the Accessors and Mutators
* List Accessors (getters) seperate and before Mutators (setters)

### Class Files
 Follow the order of methods as they are listed in the header file
