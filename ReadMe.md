# Demo JSON serialization via C++ and Nlohmann JSON library
## _Intro_
This repo contains a demo program which performs read of a .txt file
(with JSON records) and translating of the files contents into two files:
 - Binary file with input records (with keys replaced with integers)  
 - Binary file with relations between str keys and corresponding integers.  


## Usage

<program_name> <path_to_input_file> <optional-maxline-to-read-size>

Example:
```
./bin/jsonTranslator json_gen_example.txt 300
```
## Details
The program is built using C++11.
The program is not a fault proof - since it is a demo project.
The program supports only single data types - bool, string, and int.
The program implements TLV-like approach to the serialization process.

### Serialization class diagram
![Alt text](Docs/Class_diagram.png?raw=true "Diagram")


## Possible improvements
Following things can improve the program:
- The input file can be read in bug N bytes chunks - afterwards the chunks can be serialized in separate threads.
- Integer values can be even more optimized: empty bytes on left/right can be discarded; fixed number of int stored bytes can be increased 
(currently, int8, int16, int32, and int64 are supported).