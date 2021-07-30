def solution(record):
    answer = []

    dic = dict()

    for data in record:
        cmd = data.split(' ')[0]

        if cmd == 'Enter' or cmd == 'Change':
            cust_id = data.split(' ')[1]
            nick = data.split(' ')[2]
            dic[cust_id] = nick

    for data in record:
        cmd = data.split(' ')[0]
        cust_id = data.split(' ')[1]

        if cmd == 'Enter':
            answer.append(dic[cust_id] + "님이 들어왔습니다.")
        elif cmd == 'Leave':
            answer.append(dic[cust_id] + "님이 나갔습니다.")

    return answer