#!/usr/bin/env python
import pika
import time

# 建立一个实例
connection = pika.BlockingConnection(
    pika.ConnectionParameters('localhost',5672)  # 默认端口5672，可不写
    )
# 声明一个管道，在管道里发消息
channel = connection.channel()
# 在管道里声明queue
channel.queue_declare(queue='hello')
# RabbitMQ a message can never be sent directly to the queue, it always needs to go through an exchange.
while True:
    channel.basic_publish(exchange='',
                        routing_key='hello',  # queue名字
                        body='0')  # 消息内容
    print("0")
    time.sleep(20)
connection.close()  # 队列关闭