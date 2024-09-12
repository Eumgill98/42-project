# Philosophers

## 0. philo.h
- 프로그램에 사용되는 구조체
### `t_philo` : 각 철학자의 구조체  
- `int  id` : 철학자 id
- `int  dead` : 해당 철학자의 죽음 여부
- `int  eat_count` : 해당 철학자가 먹은 횟수
- `long last_eaten` : 해당 철학자가 마지막으로 먹은 시간 (ms)
- `pthread_t    *thread` : 해당 철학자의 스레드 포인터
- `pthread_mutex_t  *left_fork` : 철학자의 왼쪽 포크 뮤텍스 포인터
- `pthread_mutex_t  *right_fork` : 철학자의 오른쪽 포크 뮤텍스 포인터

### `t_program` : 해당 프로그램의 기본 정보 구조체
- `int  num_philos` : 철학자의 수
- `long time_to_die` : 죽지 않기 위한 최대 먹지 않을 수 있는 시간 (ms)
- `long time_to_eat` : 먹는데 걸리는 시간 (ms)
- `long time_to_sleep` : 자는데 걸리는 시간 (ms)
- `int end_point` : 모든 철학자가 해당 횟수 만큼 먹었을때 프로그램이 종료되는 조건
- `struct timeval   start_time` : 프로그램의 시작 시간 (ms) 구조체
- `t_philo  *philos` : 철학자 구조체 배열 포인터
