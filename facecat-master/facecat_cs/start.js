{HTTP����ص�}
function onhttprequest(){
	var(url, '', method, '', servicename, '');
	http.getrequesturl(url);
	http.getrequestmethod(method);
	http.getservicename(servicename);
	str.tolower(servicename, servicename);
	http.setstatuscode(200);
	
	out(url);
	var(ip, '');
	http.getremoteip(ip);
	out(ip);
	out(http.getremoteport());
	if(str.equals(servicename, 'login')){
	    onloginrequest();
	}
	else if(str.equals(servicename, 'wechat')) {
	    onwechatrequest();
	}
	else if(str.equals(servicename, 'hard')) {
	    http.hardrequest();
	}
	else if(str.equals(servicename, 'easy')) {
	    http.easyrequest('easy');
	}
}

{��¼����}
function onloginrequest(){
	var(name, '', pwd, '');
	http.querystring(name, 'name');
	http.querystring(pwd, 'pwd');
	http.write('name:', name, '<br/>');
	http.write('pwd:', pwd, '<br/>');
	if(str.equals(name, 'admin')
	 && str.equals(pwd, '111111')){
		http.write('Login Success!'); 
	}
	else{
		http.write('Login Fail!');
	}
}

{���ű�״̬}
function oncheckscript(){
	while(isappalive()){
		sleep(10000);
		http.checkscript();
	}
}

{΢������}
function onwechatrequest(){
	http.write('Welcome to WeChat!');
}

{HTTP����׼�������¼�}
function onhttpserverstarting(filename){
	out('ִ�нű��ļ�:', filename);	
	http.addport(8086);
	createthread('oncheckscript();');
}

{HTTP���������ɹ��¼�}
function onhttpserverstart(maxThreadNum, minThreadNum){
	out('���������ɹ�...');
	out('����߳���:', maxThreadNum);
	out('��С�����߳���:', minThreadNum);
}

{HTTP��������ʧ���¼�}
function onhttpserverstartfail(error){
	out('��������ʧ��...');
	out(error);
}