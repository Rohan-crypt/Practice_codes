import linecache
def line(n):
    file_path = 'trains.txt'
    line = linecache.getline(file_path, n)
    print(line.strip())