import copy

#### 파이썬의 copy 와 deepcopy

# copy는 주소를 가진 객체 + 주소를 가지지 않는 객체가 있을 경우, 주소 가진 객체는 그걸 그대로 가르킴. 
# deepcopy는 주소를 가진 객체 + 주소를 가지지 않는 객체가 있을 경우, 전부 다 새로 공간에 할당함. 

# https://velog.io/@burnkim61/%ED%8C%8C%EC%9D%B4%EC%8D%ACpython-%EC%96%95%EC%9D%80-%EB%B3%B5%EC%82%ACshallow-copy%EC%99%80-%EA%B9%8A%EC%9D%80-%EB%B3%B5%EC%82%ACdeep-copy#:~:text=Shallow%20copy%20%3A%20%EB%B3%B5%EC%82%AC%EB%8C%80%EC%83%81%EC%9D%80,%EC%83%88%EB%A1%9C%EC%9A%B4%20%EA%B3%B5%EA%B0%84%EC%97%90%20%ED%95%A0%EB%8B%B9%EB%90%A9%EB%8B%88%EB%8B%A4.

# mutable 객체는 : 객체를 생성한 후, 객체의 값을 수정 가능, 변수는 값이 수정된 같은 객체를 가리키게 됨. 
# 예) list, set, dict
# immutable 객체는 : 객체를 생성한 후, 객체의 값을 수정 불가능, 변수는 해당 값을 가진 다른 객체를 가리키게 됨, 
# 예 ) int, float, bool, tuple

# 쉽게 구별하는 방법은 변수에 대입한 값을 수정했을 때 전후의 id를 비교해보면 됩ㄴ디ㅏ.
# 같으면 muttable 객체, 다르면 immutable 객체입니다. 

class SelfReferenceEntity:
    def __init__(self):
        self.parent = None
    def set_parent(self, parent):
        self.parent = parent

class Somecomponent:
    def __init__(self, some_int, some_list, some_circular_ref):
        self.some_int = some_int
        self.some_list = some_list
        self.some_circular_ref = some_circular_ref

    def __copy__(self):
        some_list = copy.copy(self.some_list)
        some_circular_ref = copy.copy(self.some_circular_ref)

        new = self.__class__(self.some_int, some_list, some_circular_ref)
        new.__dict__.update(self.__dict__)

        return new


if __name__ == "__main__":
    
    list_of_objects = [1, 2, 3]
    circular_ref = SelfReferenceEntity()

    circular_ref_02 = SelfReferenceEntity()
    
    component_01 = Somecomponent(11, list_of_objects, circular_ref)
    component_02 = Somecomponent(12, list_of_objects, circular_ref_02)

    shallow_copy_component_01 = copy.copy(component_01)
    shallow_copy_component_02 = copy.copy(component_02)
    deep_copy_component_01 = copy.deepcopy(component_01)
    deep_copy_component_02 = copy.deepcopy(component_02)


    component_01.some_list.append("hihi")
    print(shallow_copy_component_01.some_list)
    print(deep_copy_component_01.some_list)