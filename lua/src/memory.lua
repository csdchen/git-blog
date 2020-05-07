collectgarbage("collect")
print(collectgarbage("count"))

local my_list = {}
for i = 1, 100, 1 do
    local v = {}
    v[1], v[2] = 1007+i, 32+i
    my_list[v[1]] = v[2]
end
print(collectgarbage("count"))
collectgarbage("collect")
print(collectgarbage("count"))
my_list = nil
print(collectgarbage("count"))
collectgarbage("collect")
print(collectgarbage("count"))

function func01()
    for i = 1, 10000 do
        local v = {}
        v[1], v[2] = 1, 2
    end    
end

func01()
print("func01  ", collectgarbage("count"))
func01()
print("func01  ", collectgarbage("count"))
func01()
print("func01  ", collectgarbage("count"))
func01()
print("func01  ", collectgarbage("count"))