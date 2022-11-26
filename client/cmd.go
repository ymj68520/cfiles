package main

import (
	"crypto/sha256"
	"encoding/hex"
	"encoding/json"
	"log"
)

type Request struct {
	Message
	Timestamp  int64
	clientAddr string
}

type PrePrepare struct {
	RequestMessage Request
	Digest         string
	SequenceID     int
	Sign           []byte
}

type Prepare struct {
	Digest     string
	SequenceID int
	NodeID     string
	Sign       []byte
}

type Commit struct {
	Digest     string
	SequenceID int
	NodeID     string
	Sign       []byte
}

type Reply struct {
	MessageID int
	NodeID    string
	Result    bool
}

type Message struct {
	Content string
	ID      int
}

const prefixCMDLength = 12

type command string

const (
	cRequest    command = "request"
	cPrePrepare command = "preprepare"
	cPrepare    command = "prepare"
	cCommit     command = "commit"
)

func jointMessage(cmd command, content []byte) []byte {
	b := make([]byte, prefixCMDLength)
	for i, v := range []byte(cmd) {
		b[i] = v
	}
	joint := make([]byte, 0)
	joint = append(b, content...)
	return joint
}

func splitMessage(message []byte) (cmd string, content []byte) {
	cmdBytes := message[:prefixCMDLength]
	newCMDBytes := make([]byte, 0)
	for _, v := range cmdBytes {
		if v != byte(0) {
			newCMDBytes = append(newCMDBytes, v)
		}
	}
	cmd = string(newCMDBytes)
	content = message[prefixCMDLength:]
	return
}

func getDigest(request Request) string {
	b, err := json.Marshal(request)
	if err!=nil{
		log.Panic(err)
	}
	hash:=sha256.Sum256(b)
	return hex.EncodeToString(hash[:])
}