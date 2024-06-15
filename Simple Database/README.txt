프로그램 사용 방법

- Database 종류 설정
List로 구현된 Database 사용 시 1
Map으로 구현된 Database 사용 시 2

- key의 종류
	"학교구분",
	"학교코드",
	"학교명칭",
	"본분교",
	"학제",
	"지역",
	"설립구분",
	"학교상태",
	"학교영어명칭",
	"주소",
	"우편번호",
	"학교개교일",
	"학교홈페이지",
	"총장명",
	"학교대표번호",
	"학교팩스번호"

- 명령어
1. SELECT key = value
입력한 key의 value가 일치하는 정보를 출력합니다.

2. INSERT key1 key2 key3.. VALUES value1 value2 value3...
각 key에 VALUE 뒤의 value를 넣은 정보를 저장합니다.
만약 하나 이상의 key를 입력하지 않았으면 그 value는 빈 정보로 저장됩니다.

3. UPDATE key1 = value1 WHERE key2 = value2
key2에 value2가 일치하는 정보에서 key1를 value1로 수정합니다.

4. DELETE key = value
입력한 key의 value가 일치하는 정보를 삭제합니다.

