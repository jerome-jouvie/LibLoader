/**
 * LibLoader
 * Copyright © 2007-2017 Jérôme Jouvie
 *
 * Created on 25 mar. 2007
 * @version file v1.0.0
 *
 * To contact me:
 * jerome.jouvie@gmail.com
 * http://jerome.jouvie.free.fr/
 *
 * INTRODUCTION
 * This project enhance the Java's System.loadLibrary and allows:
 * - library loading without loading dependencies
 * - search libraries from "java.library.path", "sun.jnlp.applet.launcher", "org.lwjgl.librarypath"
 * - library loading from applet
 *
 *
 * GNU LESSER GENERAL PUBLIC LICENSE
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA
 */

package org.jouvieje.libloader;

/**
 * dlfcn.h
 */
public interface RTLD {
	
	/* dlopen flags*/
	
	/** All undefined symbols in the library are resolved before dlopen() */
	/** Lazy function call binding */
	public static final int RTLD_LAZY		= 0x00001;
	/** symbol values are first resolved when needed */
	/** Immediate function call binding */
	public static final int RTLD_NOW		= 0x00002;
	
	/* dlopen or'ed flags */
	
	/** The external symbols defined in the library will be made available for symbol resolution */
	/** If the following bit is set in the MODE argument to 'dlopen'
	 * the symbols of the loaded object and its dependencies are made
	 * visible as if the object were linked directly into the program. */
	public static final int RTLD_GLOBAL		= 0x00100;	//available for other
	/**  */
	public static final int RTLD_LOCAL		= 0x00000;
}