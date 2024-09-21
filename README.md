# SC2001 Project 1

This is the repository for the first project of NTU's SC2001 ALGORITHM DESIGN AND ANALYSIS.

Team Members:
- Le Nguyen Bao Huy
- Loke Yongen, Gabriel
- Madhumita Thiruppathi
- Manikandan Yuvana

## About the program

The program will generate a .txt file containing randomly-generated data for the array. It will then read in from this file and sort the data using a hybrid of merge sort and insertion sort, where the sorting method used will depend on a size threshold set beforehand. After sorting, the program will output the number of key comparison used to sort the data. 

## Compilation

To compile the project, change the working directory to this project's. Then simply run the following command on the command line:

Windows:

```
    g++ -g -std=c++17 main.cpp src\*.cpp -I headers -o bin\main.exe
```

Linux:

```
    g++ -g -std=c++17 main.cpp src/*.cpp -I headers -o bin/main
```

## Running the program

Execute the program by calling it through the command line. The program accepts up to three arguments:

Windows:

```
    .\bin\main.exe [SIZE_OF_ARRAY] [SORT_THRESHOLD] [GENERATE_NEW_ARRAY]
```

Linux & MacOS:

```
    ./bin/main.exe [SIZE_OF_ARRAY] [SORT_THRESHOLD] [GENERATE_NEW_ARRAY]
```

Arguments:
- SIZE_OF_ARRAY: The size of the array to sort. This number of elements will be read from the 'Data.txt' file. Default value is 10 000 000
- SORT_THRESHOLD: The size threshold to use for switching between insertion sort and merge sort. Specifically, if SIZE <= SORT_THRESHOLD then the algorithm will use the former, otherwise it will use the latter. Default value is 4.
- GENERATE_NEW_ARRAY: A bool value on whether to generate a new array (changing the data in the file), or keep using the existing data in the file. Default value is 1 (True). Input 0 for False