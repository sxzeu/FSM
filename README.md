## game AI FSM
- Mat Buckland의 Programming Game AI by example 교재 샘플로 제공되는 ‘WestWorldWithMessaging’ project를 수정/변형해서 FSM 기반 대화 스크립트를 출력하기

## 컴파일 환경
- 컴파일 환경: visual studio 2019

## 내용
- 설정: 바쁘게 일을 하고 있는 낮 시간의 빵집
- 등장인물: Baker(제빵사) / Jane(알바생 제인) / Owner(사장)
- 바쁘게 돌아가는 낮 시간의 베이커리 특성상 서로 메시지를 주고 받으며 일이 진행되는 모습을 나타내는 것에 중점을 두었습니다.



- 알바생인 Jane은
1) 베이커리에서 근무를 합니다.
2) 빵이 다 구워졌다는 메시지를 제빵사로부터 받으면 빵을 진열합니다.
3) 매장이 더러워졌음을 알리는 변수가 일정 수준 이상이 되면 매장을 청소합니다.

- 제빵사 Baker은
1) 빵을 굽습니다. 
2) 빵이 일정 갯수 이상 구워지면 빵을 진열해달라고 알바생에게 메시지를 보냅니다.
3) 재료가 넉넉히 있는지 확인하는 변수가 일정수준 이하로 떨어지면 재료를 주문할 것을 사장에게 요청합니다.
4) 지루함을 체크하는 변수가 일정수준 이상이 되면 노래를 바꿔 듣습니다.

- 사장 Owner은
1) 매장에서 근무하며 돈을 정리합니다.
2) 돈을 체크하는 변수가 일정수준 이상이 되면 은행에 다녀옵니다.
3) 은행에 돈을 예금하고 다시 빵집으로 돌아옵니다.
4) 제빵사로부터 재료를 주문해달라는 메시지를 받으면 재료를 주문합니다.


## 참고 소스 
- Mat Buckland의 Programming Game AI by Example , chapter2 WestWorldWithMessaging.zip
