from __future__ import annotations
from abc import ABC, abstractmethod
from typing import List

#abstractmethod 가 virtual 인가봐 가상 함수, 추상 메서드를 꼭 구현해야 한데.

class Component(ABC): ## class 안에 이렇게 집어 넣는게 상속인가바
    @property
    def parent(self) -> Component:
        return self.parent

    @parent.setter
    def parent(self, parent: Component):
        self._parent = parent

    def add(self, component: Component) -> None:
        pass

    def remove(self, component: Component) -> None:
        pass

    def is_composite(self) -> bool:
        return False

    @abstractmethod
    def operation(self) -> str:
        pass


class Leaf(Component):
    def operation(self) -> str:
        return "Leaf"


class Composite(Component):
    def __init__(self) -> None:
        self._children: List[Component] = []

    def add(self, component: Component) -> None:
        self._children.append(component)
        component.parent = self
    
    def remove(self, component: Component) -> None:
        self._children.remove(component)
        component.parent = None

    def is_composite(self) -> bool:
        return True

    def operation(self) -> str:
        results = []
        for child in self._children:
            results.append(child.operation())
        return f"Branch({'+'.join(results)})"


def client_code(component: Component) -> None:
    print(f"Result:{component.operation()}", end="")


def client_code_02(component: Component, component2: Component) -> None:

    if component.is_composite():
        component.add(component2)
    print(f"Result:{component.operation()}", end="")


if __name__ == "__main__":
    simple = Leaf()
    client_code(simple)
    print('\n')

    tree = Composite()
    tree.add(Leaf())
    tree.add(Leaf())

    branch = Composite()
    branch.add(Leaf()) 
    branch.add(Leaf())

    client_code(branch)   