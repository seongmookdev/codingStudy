class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList(object):
    def __init__(self):
        self.head = None
        self.count = 0

        def append(self, node):
            if self.head == None:
                self.head = node
            else:
                curr = self.head                #curr node를 Head로 놓고
                while curr.next != None:        #curr node가 0이 아닐떄까지 
                    curr = curr.next            #curr node를 다음으로 보내고
                curr.next = node                #curr node가 마지막이면 node를 추가한다

        def getdataIndex(self, data):
            curr = self.head                    #curr node를 Head로 놓고
            idx = 0                             #index 초기화
            while curr:                         #curr을 돌면서
                if curr.data == data:           #curr의 data가 찾는 data 이면
                    return idx                  #index 반환
                curr = curr.next                #curr node를 다음으로 계속 보내면서
                idx += 1                        #index도 증가시킨다.
            return -1

        def insertModeAtIndex(self, idx, node):
            """
            A node can be added in three ways
            1) At the front of the linked list
            2) At a given index
            3) At the end of the linked list
            """
            curr = self.head
            prev = None
            curr_idx = 0

            # 1) Add 0 index
            if idx == 0:                        #제일 앞에 추가할 때
                if self.head:                   #head가 있으면
                    nextNode = self.head        #다음 노드를 Head로 놓고
                    self.head = node            #head에 Node 추가
                    self.head.next = nextn      #head의 next를 next node로 연결한다
                else:
                    self.head = node
            
            else:
            # 2) Add at given index &
            # 3) At the end of the linked list
                while curr_idx < idx:
                    if curr:
                        prev = curr
                        curr = curr.next
                    else:
                        break
                    curr_idx += 1
                
                if curr_idx == idx:
                    node.next = curr
                    prev.next = node

                else:
                    return -1





    