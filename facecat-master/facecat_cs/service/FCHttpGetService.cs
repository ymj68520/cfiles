/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu);
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.IO;
using System.IO.Compression;
using OwLib;

namespace FaceCat {
    /// <summary>
    /// HTTP��GET����
    /// </summary>
    public class FCHttpGetService {
        /// <summary>
        /// ����HTTP����
        /// </summary>
        public FCHttpGetService() {
        }

        /// <summary>
        /// ��ȡ��ҳ����
        /// </summary>
        /// <param name="url">��ַ</param>
        /// <returns>ҳ��Դ��</returns>
        public static String get(String url) {
            String content = "";
            HttpWebRequest request = null;
            HttpWebResponse response = null;
            StreamReader streamReader = null;
            Stream resStream = null;
            try {
                request = (HttpWebRequest)WebRequest.Create(url);
                request.KeepAlive = false;
                request.Timeout = 10000;
                ServicePointManager.DefaultConnectionLimit = 50;
                response = (HttpWebResponse)request.GetResponse();
                resStream = response.GetResponseStream();
                streamReader = new StreamReader(resStream, Encoding.Default);
                content = streamReader.ReadToEnd();
            }
            catch (Exception ex) {
            }
            finally {
                if (response != null) {
                    response.Close();
                }
                if (resStream != null) {
                    resStream.Close();
                }
                if (streamReader != null) {
                    streamReader.Close();
                }
            }
            return content;
        }
    }
}
