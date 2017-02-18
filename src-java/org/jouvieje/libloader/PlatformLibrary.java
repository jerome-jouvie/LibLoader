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

public final class PlatformLibrary {
	public final String libraryName;
	public final String libraryFullName;
	public final boolean optional;
	public PlatformLibrary(String libraryName, String libraryFullName) {
		this(libraryName, libraryFullName, true);
	}
	public PlatformLibrary(String libraryName, String libraryFullName, boolean optional) {
		this.libraryName = libraryName;
		this.libraryFullName = libraryFullName;
		this.optional = optional;
	}
}