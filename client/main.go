package main

import (
	"fmt"
	"log"
	"os"
)

const nodeCount = 4

//客户端的监听地址
var clientAddr = ":8888"

//节点池，主要用来存储监听地址
var nodeTable map[string]string

func main() {
	//为四个节点生成公私钥
	genRsaKeys()
	nodeTable = map[string]string{
		"N0": "127.0.0.1:8000",
		"N1": "127.0.0.1:8001",
		"N2": "127.0.0.1:8002",
		"N3": "127.0.0.1:8003",
	}
	fmt.Println(os.Args)
	if len(os.Args) != 2 {
		log.Panic("输入的参数有误！")
	}
	nodeID := os.Args[1]
	if nodeID == "client" {
		clientSendMessageAndListen() //启动客户端程序
	} else if addr, ok := nodeTable[nodeID]; ok {
		p := NewPBFT(nodeID, addr)
		go p.tcpListen() //启动节点
	} else {
		log.Fatal("error！")
	}
	select {}
}
