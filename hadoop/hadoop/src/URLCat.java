public class URLCat{
	static {
	URL.setURLStreamHandleFactory( new FsUrlStreamHandlerFactory());
	}
	public static void main( String args[]) throw Exception{
		InputStream in = null;
		try{
		in = new URL(args[0]).openStream() ;
		IOUtils.copyBytes(in System.out,4096 , false);
		}finally{
			IOUtils.closeStream(in);
		}
	}
}
