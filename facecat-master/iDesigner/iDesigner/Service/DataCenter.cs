/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace FaceCat
{
    /// <summary>
    /// ��������
    /// </summary>
    public class DataCenter
    {
        private static UserCookieService m_userCookieService = new UserCookieService();

        /// <summary>
        /// ��ȡ�û�Cookie����
        /// </summary>
        public static UserCookieService UserCookieService
        {
            get { return m_userCookieService; }
        }


        /// <summary>
        /// ��ȡ����·��
        /// </summary>
        /// <returns>����·��</returns>
        public static String GetAppPath()
        {
            return Application.StartupPath;
        }

        /// <summary>
        /// �û����ݴ洢·��
        /// </summary>
        /// <returns>����·��</returns>
        public static String GetUserPath()
        {
            String userPath = Environment.GetEnvironmentVariable("LOCALAPPDATA");
            if (!FCFile.isDirectoryExist(userPath))
            {
                userPath = GetAppPath();
            }
            else
            {
                userPath += "\\idesigner";
                if (!FCFile.isDirectoryExist(userPath))
                {
                    FCFile.createDirectory(userPath);
                }
            }
            return userPath;
        }
    }
}
