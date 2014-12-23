i = int(raw_input())
n = i - 1
h = int(raw_input())

low = n * ( n + 1) / 2
high = ( h * (h + 1) / 2) - (i * (i + 1)/ 2) 
print low == high
print low, high
