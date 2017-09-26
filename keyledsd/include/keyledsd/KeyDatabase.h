/* Keyleds -- Gaming keyboard tool
 * Copyright (C) 2017 Julien Hartmann, juli1.hartmann@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef KEYLEDSD_KEYDATABASE_H_E8A1B5AF
#define KEYLEDSD_KEYDATABASE_H_E8A1B5AF

#include <map>
#include <string>
#include "keyledsd/RenderLoop.h"

namespace keyleds {

/****************************************************************************/

class KeyDatabase final
{
public:
    class Key final
    {
    public:
        struct Rect { unsigned x0, y0, x1, y1; };
    public:
        RenderTarget::key_descriptor    index;      ///< index in render targets
        int                             keyCode;    ///< linux input event code
        std::string                     name;       ///< user-readable name
        Rect                            position;   ///< physical position on keyboard
    };

    typedef std::map<std::string, Key>  key_map;
    typedef key_map::const_iterator     iterator;
    typedef key_map::size_type          size_type;
public:
                    KeyDatabase(key_map keys);

    iterator        find(const std::string & name) const { return m_keys.find(name); }
    iterator        find(RenderTarget::key_descriptor) const;
    iterator        begin() const { return m_keys.cbegin(); }
    iterator        end() const { return m_keys.cend(); }
    size_type       size() const noexcept { return m_keys.size(); }

    Key::Rect       bounds() const { return m_bounds; }

private:
    static Key::Rect computeBounds(const key_map &);

private:
    const key_map   m_keys;
    const Key::Rect m_bounds;
};

/****************************************************************************/

}

#endif
