package lab.java.servletbasic;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.Servlet;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletA implements Servlet {
	ServletConfig config = null;

	public void init(ServletConfig config) {
		this.config = config;
		System.out.println("servlet is initialized");
	}

	@SuppressWarnings("unused")
	public void service(ServletRequest req, ServletResponse res) throws IOException, ServletException {

		HttpServletRequest request;
		HttpServletResponse response;
		
		try{
			request = (HttpServletRequest)req;
			response = (HttpServletResponse)res;
		}catch(ClassCastException e){
			throw new ServletException("non-HTTP request or response");
		}
		
		res.setContentType("text/html");

		PrintWriter out = res.getWriter();
		out.print("<html><body>");
		out.print("<b>hello simple servlet</b>");
		out.print("</body></html>");
	}

	public void destroy() {
		System.out.println("servlet is destroyed");
	}

	public ServletConfig getServletConfig() {
		return config;
	}

	public String getServletInfo() {
		return "copyright 2007-1010";
	}
}
