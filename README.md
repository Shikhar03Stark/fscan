# FScan

Finds files matching a filter (fast!)

## Build & Run

**Build**
```bash
cmake -B build && cmake --build build;
```

**Run**
```bash
./build/fscan <args>
```

## Usage

### 1. Search file(s) matching a suffix in a directory

`fscan -f 'hello.txt'` matches all the files with suffix having **hello.txt** in
the order of closest match heuristic

### 2. Limit matched files output

`fscan -f '.txt' -n 10` gives top 10 matching files with the suffix

### 3. Recursively find files matching the suffix

`fscan -f 'hello.txt' -R` matches all the files with suffix, in 
the order of closest match heuristic and depth of directory

### 4. Specify multiple search directory roots (cwd is default)

`fscan -d ../build -d ../build_debug -f 'libstd.a'` searches for suffix libstd.a in 
`../build` and `../build_debug` directory

## Advanced Filters

1. Searching files `before`, `between` or `after` given time
2. Searching files touched by a user or group
3. Search file name using regex (`.*^$\d\s` and ranges)

## Errors

1. Give warning if permission errors are encountered (or ignore)
2. Use stderr stream for error logs

## Purpose

I'm creating this project to get hands-on on Modern C++ constructs and programming.
I'll keep the src code maintainable, testable and fast.

Will use CMake, Gtest for tooling and testing and C++23