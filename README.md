# **MineSweeper**

2020-1 객체지향프로그래밍 최종 프로젝트

#객체지향프로그래밍 프로젝트

> 이번 객체지향프로그래밍 프로젝트 주제는 “지뢰찾기” 게임을 만드는것입니다. 지뢰찾기 게임은 맵이 출력되고, 사용자가 위치를 선택하면, 지 뢰가 아닐 경우는, 게임을 계속 진행하고, 지뢰를 제외한 위치를 모두 오픈한 경우 게임에서 승리하고, 만일 지뢰 위치를 선택한 경우는 게임에서 지게 되는 단순한 규칙을 가지고 있는 게임입니다.
> 

다음과 같은 방향으로 어플을 갭ㄹ 하였습니다. 

- 1)모든 변수 및 함수는 클래스에 포함되어야 한다.단, cout을 통한 객체 출력의 경우 예외
- 2)게임에서 제공하는 기능은 메뉴를 정해서 운영한다.
- 3)사용자가 요청한 크기의 맵을 생성해야 한다.
- 4)사용자가 선택한 난이도(상,중,하)에 따라, 지뢰 개수를 맵 크기의 10% (하), 20%(중), 30%(상) 개수만큼 랜덤 배치한다. 지뢰는 같은 곳에 중 복 배치될 수 없다. 맵의 크기와 난이도는 사용자로부터 입력 받는다.
- 5)프로젝트의 승리와 패배 조건이 명확하게 정의되어 있어야 한다.
- 6)프로젝트에는 MineSweeper라는 클래스가 반드시 존재해야 하며, 이클래스에 play()라는 멤버함수를 만들고, 이 함수의 기능은 게임을 시작 하는 기능을 담당하게 한다. main() 함수에서는 이 MineSweeper클래스의 객체 만들고, 그 객체의 play() 함수 호출로 게임을 시작한다.
- 7)런타임 오류로 프로그램이 종료되지 않도록 예외처리가 잘 되어 있어야 한다.
- 8)주어진 윈도우 API를 사용하여 사용자 인터페이스를 개선한다. 리눅스 및 기타 OS 사용자는 본인 OS 맞추어 UI 개선 할 것
- 9)종료 시 모든 폭탄의 위치를 출력한다.
- 10)지뢰가 아닌 곳을 선택할 경우, 자동 펼침을 수행해야 한다.
- 11)자동 펼침 제공시 주변 지뢰 개수를 힌트로 제공해야 한다.
- 12)게임을 중간에 중단할 경우, 저장하기 및 이어하기 기능을 제공한다.
- 13)게임이 종료 되면, 게임 진행 과정을 리플레이를 시켜준다.

## 흐름도

이전에 게임을 실행한적 없이 청므으로 게임을 실행한 경우 입니다. 

![image01](https://user-images.githubusercontent.com/70648111/149278814-fb44304c-02b8-41ef-a243-ee55c7a1d5e8.png)

이전에 게임을 한 데이터가 있으며 이기거나 지는 결과까지 보는 경우 입니다.

![image02](https://user-images.githubusercontent.com/70648111/149278818-600e2a93-b784-4a92-98ba-83a8704a86dc.png)

txt파일을 통해서 이전에 진행중이던 게임을 이어서 하는 경우입니다.

![image03](https://user-images.githubusercontent.com/70648111/149278819-135981f4-5c93-4272-9146-18fe5d9048f1.png)

- 메인메뉴
    
![메인메뉴](https://user-images.githubusercontent.com/70648111/149278826-7b717fcb-fd20-43f5-a6ef-33c0be7beb80.png)
    
![지뢰1](https://user-images.githubusercontent.com/70648111/149278831-2312badf-23cd-47f7-b784-56144ed41f69.gif)
    
- 맵 생성
    
![맵생성](https://user-images.githubusercontent.com/70648111/149278823-0ebc6e46-e15c-4d15-8fe6-b6bb720d60ac.png)
    
- 게임 화면
    
![게임화면](https://user-images.githubusercontent.com/70648111/149278820-e9f7ecbe-66f3-41a1-81fe-6a258251f0a3.png)
    
![게임화면2](https://user-images.githubusercontent.com/70648111/149278821-e79beadd-cb5a-46f5-ac65-d95d84c3e428.png)
    
- 패배
    
![패배](https://user-images.githubusercontent.com/70648111/149278878-d9a46d25-3cf5-4aed-beee-e590dab3ed6a.png)
    
![지뢰2](https://user-images.githubusercontent.com/70648111/149278837-0203f84d-2677-4aea-8b99-849bca9aa1dc.gif)
    
- 승리/리플레이
    
![승리](https://user-images.githubusercontent.com/70648111/149278827-77825466-464b-40ba-a9bb-a3ddfd594a75.png)
    
![지뢰5](https://user-images.githubusercontent.com/70648111/149278863-056b601e-ecf0-40aa-8cb4-adf890d42ee5.gif)
    
- 파일저장
    
![파일저장](https://user-images.githubusercontent.com/70648111/149278877-9b2bb406-131e-4848-9096-d8d2b40df506.png)
    
![지뢰4](https://user-images.githubusercontent.com/70648111/149278842-0d7d4f13-fc30-485b-a134-7661206eabb3.gif)
