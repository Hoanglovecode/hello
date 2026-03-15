s="Hello le van hoang"
# Hàm list() dùng để biến object thành list các phần tử
a=list(s)
print(a)
b=list(range(20))
print(b)
# Hàm len()
print(len(s))
c=['a','b']
print(len(c)) #2
d=[1,2,3,4,5,6,7,5,6]
for i in range(len(d)):
    print(d[i],end=' ')
print() #xuống dòng
for i in range(len(d)-1,-1,-1):
    print(d[i],end=' ')
print()
# Duyệt bằng for each
for item in d:
    print(item,end=' ')
print()
# Hàm thêm 1 phần tử vào cuối
e=[1,2,3,4]
e.append(5)
print(e)
e.append(7)
print(e)
# Hàm thêm phần tử vào vị trí index mong muốn
g=[1,2,4,3,4,3]
g.insert(3,45) #insert(index,value)
print(g)
# Xóa phần tử
# Dùng pop() nếu muốn lấy phần tử xóa còn không thì dùng del()
q=[1,2,3,4]
q.pop(2) #xóa phần tử vị trí index 2 là value 3
q.pop() #nếu k đề cập index thì tự động xóa value ở cuối
print(q)
# remove(value) xóa giá trị duy nhất
r=[1,2,3,4,3,3,3]
r.remove(3) 
print(r)
r.remove(4)
print(r)
# Muốn xóa hết phần tử dùng clear()
r.clear()
print(r)
# Tạo list và nhân bản list
a2=[0]*1000 #Tạo mảng 1 chiều a với 1000 phần tử 0
s=[1,2,3,4,5]
s1=s*2
print(s1)
# thêm các phần tử list khác vào extend()
m=[1,2,3,4]
k=[4,5,6,6,6,6]
m.extend(k)
print(m)
# count(n) số lần phần tử xuất hiện trong list
print(k.count(6)) #4
# index(value) sẽ trả về vị trí index của giá trị đó
print(m.index(3)) #2
# Hàm sort() làm thay đổi mảng và sắp xếp tăng dần
# Hàm reverse() đảo ngược mảng
m.reverse()
print(m)
# hàm sorted khác sort là nó trả về list đã sắp xếp nhưng k làm thay đổi tính chất mảng ban đầu
# all() trả về true nếu all true
# any() trả  về true nếu 1 trong all true
# sum() tổng all phần tử trong list
# max() min()
