# file handing 

#saving a dictornery in a text file 
with open("my_dict.txt", "w") as file:
    my_dict = {"name": "Alice", "age": 30, "city": "New York"}
    file.write(str(my_dict)) 

#converting it back to  withour eval
with open("my_dict.txt", "r") as file:
    content = file.read()
    my_dict = eval(content) 
    print(my_dict)

#serialization with json
''' Process of converting a data types into JSON format is called serialization.''' 
#deserialization
''' The process of converting JSON format back to data types.'''

import json

#serialization with json
my_dict = {"name": "Vanshika", "age": 18, "Gender": "Female"}
with open("my_dict.json", "w") as file:
    json.dump(my_dict, file)

#deserialization with json
with open("my_dict.json", "r") as file:
    my_dict_from_file = json.load(file)
    print(my_dict_from_file) 

#exception of json
t = (1, 2, 3)
with open("tuple.json", "w") as file:
    json.dump(t, file)
with open("tuple.json", "r") as file:
    t_from_file = json.load(file)
    print(t_from_file)  # Output: [1, 2, 3] 
#create a class with multiple datatype and try to serialize it with json and deserialize it back to the class object
class person:
    def __init__(self, name, age, city):
        self.name = name
        self.age = age
        self.city = city  
person1 = person("Vanshika", 18, "Delhi")
with open("person.json", "w") as file:
    json.dump(person1.__dict__, file)
with open("person.json", "r") as file:
    person_data = json.load(file)
    person_from_file = person(**person_data)
    print(person_from_file.name)  # Output: Vanshika
    print(person_from_file.age)   # Output: 18
    print(person_from_file.city)  # Output: Delhi 

    